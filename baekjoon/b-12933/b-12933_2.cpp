#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s;
vector<vector<int>> idx(5);
int visit[500] = {0, };

int qtoi(char c) {
    if(c == 'q') return 0;
    else if(c == 'u') return 1;
    else if(c == 'a') return 2;
    else if(c == 'c') return 3;
    else if(c == 'k') return 4;
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    for(int i = 0; i < s.length(); ++i)
        idx[qtoi(s[i])].push_back(i);

    int ans = 0;
    bool flag = true;

    size_t sz = idx[0].size();
    for(int i = 1; i < 5; ++i) {
        if(sz != idx[i].size()) {
            flag = false;
            goto ans;
        }
    }

    for(int i = 0; i < sz; ++i) {
        for(int j = 0; j < 4; ++j) {
            if(idx[j][i] >= idx[j+1][i]) {
                flag = false;
                goto ans;
            }
        }
    }

ans: 
    if(!flag) ans = -1;
    else {
        for(int i = 0; i < sz; ++i) {
            if(visit[i]) continue;
            int t = i;
            int last_k = idx[4][t];

            while(1) {
                visit[t] = 1;
                auto it = upper_bound(idx[0].begin() + t + 1, idx[0].end(), last_k);

                if(it == idx[0].end()) {
                    ans += 1;
                    break;
                }
                t = it - idx[0].begin();
                if(!visit[t]) last_k = idx[4][t];
            }
        }
    }

    cout << ans << '\n';

    return 0;
}