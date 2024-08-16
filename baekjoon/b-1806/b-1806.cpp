#include <iostream>
#include <algorithm>

using namespace std;

int n, s, arr[100000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; ++i) cin >> arr[i];

    int st = 0, en = 0, sum = arr[0], ans = 100001;
    while(true) {
        if(sum < s) {
            en++;
            if(en == n) break;
            sum += arr[en];
        }
        else {
            ans = min(ans, en - st + 1);
            sum -= arr[st];
            st++;
        }
    }

    if(ans == 100001) ans = 0;
    cout << ans << '\n';

    return 0;
}