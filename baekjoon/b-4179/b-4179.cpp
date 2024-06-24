#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int R, C;
char map[1000][1000] = {0, };
int visited[1000][1000] = {0, };
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
queue<pair<int, int>> floc;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    int ans = 0;

    visited[x][y] = 1;
    q.push({x, y});

    int tmp = 0;

    while(!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        // caution: 지훈이의 시간 t에 대한 위치 하나에 대해서만 불 확산
        if(visited[curx][cury] != tmp) {
            tmp = visited[curx][cury];

            // caution: 시간 t에 있던 불에 대해서만 확산
            int sz = floc.size();
            while(sz--) {
                int curx = floc.front().first;
                int cury = floc.front().second;
                floc.pop();

                for(int i = 0; i < 4; ++i) {
                    int nx = curx + dx[i];
                    int ny = cury + dy[i];

                    if(nx < 0 || ny < 0 || nx >= R || ny >= C)
                        continue;
                    
                    if(map[nx][ny] == 'F' || map[nx][ny] == '#')
                        continue;
                    
                    map[nx][ny] = 'F';
                    floc.push({nx, ny});
                }
            }
        }

        for(int i = 0; i < 4; ++i) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if(nx < 0 || ny < 0 || nx >= R || ny >= C) {
                ans = visited[curx][cury];
                break;
            }
                
            if(visited[nx][ny] != 0 || map[nx][ny] == 'F' || map[nx][ny] == '#')
                continue;
            
            visited[nx][ny] = visited[curx][cury] + 1;
            q.push({nx, ny});
        }

        // caution: 바깥 for문 break
        if(ans != 0)
            break;
    }

    if(ans == 0)
        cout << "IMPOSSIBLE" << '\n';
    else
        cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y;

    cin >> R >> C;
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            cin >> map[i][j];

            if(map[i][j] == 'J') {
                x = i;
                y = j;
            }
            else if(map[i][j] == 'F') {
                floc.push({i, j});
            }
        }
    }

    bfs(x, y);    

    return 0;
}