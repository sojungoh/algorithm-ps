#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char q[5] = {'q', 'u', 'a', 'c', 'k'};
string s;

int solve() {
    vector<bool> v(s.length(), 0);
    vector<int> index;
    int ans = 0, sum = 0;

    // 'q' index 저장
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == 'q') index.push_back(i);
    }

    for(int i : index) {
        // 이미 방문한 'q' 사운드면 건너뜀
        if(v[i]) continue;
        int ik = i - 1;

        while(1) {
            // 연속된 quack 찾기
            for(int j = 0; j < 5; ++j) {
                auto it = find(s.begin() + ik + 1, s.end(), q[j]);
                if(it == s.end()) return -1;
                
                ik = it - s.begin();
                // 이미 방문한 q[j]이면 다시 탐색
                if(v[ik]) {
                    j--;
                    continue;
                }
                //cout << ik << ": " << q[j] << '\n';
                v[ik] = 1;
                sum += 1;
            }

            // 같은 오리가 내는 소리인 다음 q 찾기
            auto it = lower_bound(index.begin(), index.end(), ik);
            if(it == index.end() || v[*it]) {
                ans += 1;
                break;
            }
            ik = *it - 1;
        }    
    }

    if(sum != s.length()) return -1;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    cout << solve() << '\n';

    return 0;
}