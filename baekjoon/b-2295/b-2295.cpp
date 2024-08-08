#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, arr[1000];
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr+n);

    for(int i = 0; i < n; ++i)
        for(int j = i; j < n; ++j)
            v.push_back(arr[i]+arr[j]);

    for(int i = n-1; i >= 0; --i) {
        for(int j=0; j < v.size(); ++j) {
            if(arr[i]-v[j] > 0 && binary_search(arr, arr+n, arr[i]-v[j])) {
                cout << arr[i] << '\n'; 
                return 0;
            }
        }
    }

    return 0;
}