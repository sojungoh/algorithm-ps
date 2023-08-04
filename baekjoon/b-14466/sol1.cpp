#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int N, K, R;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K >> R;
    
    vector<vector<set<pii>>> road(N + 1, vector<set<pii>>(N + 1));
    for(int i = 0; i < R; ++i) {
        int sr, sc, dr, dc;
        cin >> sr >> sc >> dr >> dc;
        road[sr][sc].insert({dr, dc});
        road[dr][dc].insert({sr, sc});
    }

    set<pii> cows;
    for(int i = 0; i < K; ++i) {
        int r, c;
        cin >> r >> c;
        cows.insert({r, c});
    }
    
    int answer = K * (K - 1) / 2;
    int visited[101][101] = {0, };
    for(auto c : cows) {
        if(visited[c.first][c.second] < 0)
            continue;

        visited[c.first][c.second] = -1;
        
        bool flag = false;
        int count = 1;
        queue<pair<int, int>> q;
        q.push(c);

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if(nx < 1 || ny < 1 || nx > N || ny > N)
                    continue;
                
                if(visited[nx][ny] != 0)
                    continue;
                
                if(road[x][y].find({nx, ny}) != road[x][y].end())
                    continue;
                
                if(cows.find({nx, ny}) != cows.end()) {
                    flag = true;
                    count++;
                    visited[nx][ny] = -1;
                }
                else
                    visited[nx][ny] = 1;
                
                q.push({nx, ny}); 
            }
        }

        if(flag)
            answer -= count * (count - 1) / 2;

        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= N; ++j)
                if(visited[i][j] > 0) 
                    visited[i][j] = 0;
    }

    cout << answer << '\n';

    return 0;
}