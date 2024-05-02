#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, answer = 0;
int init_board[20][20] = {0, };
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}; // nwse

void calculate(vector<int>& dir) {
    int trans_board[20][20];

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            trans_board[i][j] = init_board[i][j];
        }
    }
    
    for(int d : dir) {
        int other_d = (d < 2) ? d + 2 : d - 2;

        for(int i = 0; i < N; ++i) {
            queue<int> q;
            int j = (d < 2) ? 0 : N - 1;
            int c = (d < 2) ? 1 : -1;

            int curr = 0, next = 0;
            for(; j >= 0 && j < N; j += c) {
                if(curr == 0)
                    curr = (d % 2 == 0) ? trans_board[j][i] : trans_board[i][j];
                else if(next == 0)
                    next = (d % 2 == 0) ? trans_board[j][i] : trans_board[i][j];

                if(curr == 0 || next == 0)
                    continue;
                
                if(curr == next) {
                    q.push(curr * 2);
                }
                else {
                    q.push(curr);
                    j -= c;
                }
                curr = 0;
                next = 0;
            }

            if(curr != 0)
                q.push(curr);

            j = (d < 2) ? 0 : N - 1;

            for(; j >= 0 && j < N; j += c) {
                int* p = (d % 2 == 0) ? &trans_board[j][i] : &trans_board[i][j];
                
                if(!q.empty()) {
                    *p = q.front();
                    q.pop();
                }
                else
                    *p = 0;
            }
        }

        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                answer = max(answer, trans_board[i][j]);
            }
        }
    }
}

void solve(vector<int>& dir) {
    if(dir.size() == 5) {       
        calculate(dir);
        return;
    }

    for(int i = 0; i < 4; ++i) {
        dir.push_back(i);
        solve(dir);
        dir.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> init_board[i][j];
        }
    }

    vector<int> v;
    solve(v);
    
    cout << answer << '\n';   

    return 0;
}
