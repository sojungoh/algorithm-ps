#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int N, M;
int D[2], C[2];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

struct Info {
    int count;
    int x;
    int y;
    int dir;

    Info(int c, int x, int y, int d): count(c), x(x), y(y), dir(d) {}

    bool operator < (const Info& a) const {
        return count > a.count;
    }
};

bool fall_by_gravity(vector<vector<pii>>& grid, int& x, int& y, int d) {
    while(true) {
        int nx = x + dx[d];
        int ny = y;

        if(nx < 1 || nx > N)
            return false;

        if(grid[nx][ny].first == -1)
            break;
        x = nx;
        y = ny;

        if(x == D[0] && y == D[1])
            break;
    }
    return true;
}

int solve(vector<vector<pii>>& grid) {
    int answer = -1;
    priority_queue<Info> pq;

    if(!fall_by_gravity(grid, C[0], C[1], 2))
        return answer;
   
    pq.push(Info(0, C[0], C[1], 2));

    while(!pq.empty()) {
        int flip_count = pq.top().count;
        int x = pq.top().x;
        int y = pq.top().y;
        int d = pq.top().dir;
        
        pq.pop();

        if(d == 0) {
            if(grid[x][y].first <= flip_count)
                continue;
            grid[x][y].first = flip_count;
        }
        else {
            if(grid[x][y].second <= flip_count)
                continue;
            grid[x][y].second = flip_count;
        }

        // for(int i = 1; i <= N; ++i) {
        //     for(int j = 1; j <= M; ++j) {
        //         cout << grid[i][j].first << ' ' << grid[i][j].second << '\t';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        if(x == D[0] && y == D[1]) {
            return flip_count;
        }

        int nx = x;
        int ny = y;
        if(fall_by_gravity(grid, nx, ny, 2 - d)) {
            int pi = (d == 0) ? grid[nx][ny].second : grid[nx][ny].first;
            if(pi > flip_count + 1)
                pq.push(Info(flip_count + 1, nx, ny, 2 - d));
        }
       
        for(int i = 1; i < 4; i += 2) {
            nx = x;
            ny = y + dy[i];

            if(ny < 1 || ny > M)
                continue;
            if(grid[nx][ny].first == -1)
                continue;

            if(nx == D[0] && ny == D[1]) {
                answer = flip_count;
                return answer;
            }

            if(!fall_by_gravity(grid, nx, ny, d))
                continue;
            
            int pi = (d == 0) ? grid[nx][ny].first : grid[nx][ny].second;
            if(pi <= flip_count)
                continue;

            pq.push(Info(flip_count, nx, ny, d));
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    vector<vector<pii>> grid(N + 1, vector<pii>(M + 1));
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            char c;
            cin >> c;

            switch(c) {
                case 'C':
                    C[0] = i, C[1] = j;
                    grid[i][j] = {int(1e9), int(1e9)};
                    break;
                case 'D':
                    D[0] = i, D[1] = j;
                    grid[i][j] = {int(1e9), int(1e9)};
                    break;
                case '.':
                    grid[i][j] = {int(1e9), int(1e9)};
                    break;
                default:
                    grid[i][j] = {-1, -1};
                    break;
            }
        }
    }

    cout << solve(grid) << '\n';

    return 0;
}
