#include <iostream>

using namespace std;

int a[100001], cnt[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i <= 100000; ++i) cnt[i] = 0;

    int s = 0, e = 1;
    long long ans = n; // 타입 주의
    cnt[a[s]] += 1;

    while(e < n) {
        if(cnt[a[e]] >= 1) 
            cnt[a[s++]] -= 1;
        else {
            ans += (e - s);
            cnt[a[e++]] += 1;
        }
    }

    cout << ans << '\n';

    return 0;
}