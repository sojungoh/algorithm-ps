#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C, N;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
char **cave;

void throw_arrow(int r, bool from_right) {
    int i = (from_right) ? C - 1 : 0;
    int j = (from_right) ? -1 : 1;

    while(0 <= i && i < C) {
        if(cave[r][i] == 'x') {
            cave[r][i] = '.';
            break;
        }
        i += j;
    }
}

int bottom_idx = 0;
void dfs(priority_queue<pair<int, int>>& pq, vector<vector<bool>>& visited, int x, int y) {
    if(bottom_idx < x)
        bottom_idx = x;

    pq.push({x, y});

    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= R || ny >= C)
            continue;
        
        if(visited[nx][ny] || cave[x][y] == '.')
            continue;
        
        visited[nx][ny] = 1;
        dfs(pq, visited, nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    cave = new char*[R];
    for(int i = 0; i < R; ++i)
        cave[i] = new char[C];

    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j)
            cin >> cave[i][j];
    
    cin >> N;
    for(int k = 0; k < N; ++k) {
        int q;
        cin >> q;

        throw_arrow(q, k % 2);

        vector<vector<bool>> visited(R, vector<bool>(C, 0));
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                if(visited[i][j] || cave[i][j] == '.')
                    continue;
                
                priority_queue<pair<int, int>> pq;
                visited[i][j] = true;
                dfs(pq, visited, i, j);

                if(bottom_idx != R - 1) {
                    // ????
                }

                
            }
        }
    }

    for(int i = 0; i < R; ++i)
        delete cave[i];
    delete cave;

    return 0;
}