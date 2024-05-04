#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M, x, y;
int map[20][20], dice[6] = {0, 0, 0, 0, 0, 0};
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};  //ewns

void solve(int d) {
    int nx = x + dx[d - 1];
    int ny = y + dy[d - 1];

    if(nx < 0 || ny < 0 || nx >= N || ny >= M)
        return;
    
    if(d == 1) {
        int tmp = dice[2];
        dice[2] = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[5];
        dice[5] = tmp;
    }
    else if(d == 2) {
        int tmp = dice[3];
        dice[3] = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = tmp;
    }
    else if(d == 3) {
        int tmp = dice[1];
        dice[1] = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = tmp;
    }
    else if(d == 4) {
        int tmp = dice[5];
        dice[5] = dice[4];
        dice[4] = dice[0];
        dice[0] = dice[1];
        dice[1] = tmp;
    }

    if(map[nx][ny] == 0) {
        map[nx][ny] = dice[5];
    }
    else {
        dice[5] = map[nx][ny];
        map[nx][ny] = 0;
    }

    x = nx;
    y = ny;

    cout << dice[0] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> N >> M >> x >> y >> k;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < k; ++i) {
        int d;
        cin >> d;
        solve(d);
    }

    return 0;
}