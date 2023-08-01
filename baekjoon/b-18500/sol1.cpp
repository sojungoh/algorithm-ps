#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int R, C, N;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
char **cave;

bool flag = false;
void dfs(set<pair<int, int>>& coord, vector<vector<bool>>& visited, int x, int y) {
    if(x == R - 1)
        flag = true;

    coord.insert({x, y});

    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= R || ny >= C)
            continue;
        
        if(visited[nx][ny] || cave[nx][ny] == '.')
            continue;

        visited[nx][ny] = 1;
        dfs(coord, visited, nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    cave = new char*[R];
    for(int i = 0; i < R; ++i)
        cave[i] = new char[C];

    vector<set<int>> row(R);
    vector<set<int>> col(C);

    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            cin >> cave[i][j];
            if(cave[i][j] == 'x') {
                row[i].insert(j);
                col[j].insert(i);         
            }
        }
    }
    
    cin >> N;
    for(int k = 0; k < N; ++k) {
        int q;
        cin >> q;
        q = R - q;

        if(row[q].empty())
            continue;

        auto dst = (k % 2) ? --row[q].end() : row[q].begin();
        cave[q][*dst] = '.';
        col[*dst].erase(q);
        row[q].erase(dst);

        vector<vector<bool>> visited(R, vector<bool>(C, false));
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                if(visited[i][j] || cave[i][j] == '.')
                    continue;
                
                set<pair<int, int>> coord;
                visited[i][j] = true;
                dfs(coord, visited, i, j);

                if(flag) {
                    flag = false;
                    continue;
                }

                int diff = R;
                for(auto iter = coord.rbegin(); iter != coord.rend(); ++iter) {
                    int x = iter->first;
                    int y = iter->second;

                    auto tmp = col[y].find(x);
                    
                    int t = R;
                    if(++tmp != col[y].end()) {
                        if(coord.find({*tmp, y}) != coord.end())
                            continue;
                        t = *tmp;
                    }
                    
                    diff = min(diff, t - x - 1);
                }

                for(auto p : coord) {
                    cave[p.first][p.second] = '.';
                    row[p.first].erase(p.second);
                    col[p.second].erase(p.first);
                }

                for(auto p : coord) {
                    cave[p.first + diff][p.second] = 'x';
                    row[p.first + diff].insert(p.second);
                    col[p.second].insert(p.first + diff);
                    visited[p.first + diff][p.second] = true;
                } 
            }
        }
    }

    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            cout << cave[i][j];
        }
        cout << '\n';
    }
    cout << '\n';

    for(int i = 0; i < R; ++i)
        delete cave[i];
    delete cave;

    return 0;
}