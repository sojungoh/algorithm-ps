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

    int ans = int(2e9);
    for(int i = 0; i < n; ++i) {
        int x = arr[i] + m;
        int idx = lower_bound(arr+i, arr+n, x) - arr;
        if(idx != n)
            if(ans > arr[idx] - arr[i]) ans = arr[idx] - arr[i]; 
    }

    cout << ans << '\n';

    return 0;
}