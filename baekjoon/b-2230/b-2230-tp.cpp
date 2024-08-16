// 투포인터 풀이
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, arr[100000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr+n);

    int st = 0, en = 0, ans = int(2e9);
    while(en != n && st != n) {
        if(arr[en] - arr[st] < m) en++;
        else {
            ans = min(ans, arr[en] - arr[st]);
            st++;
        }
    }

    cout << ans << '\n';

    return 0;
}