#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> pv;

void prime() {
    vector<int> v;
    v.resize(n+1);

    for(int i=2; i<=n; ++i) v[i]=i;
    
    for(int i=2; i*i<=n; ++i) {
        if(v[i]) {
            for(int j=i*i; j<=n; j+=i) v[j]=0;
        }
    }

    for(int i=2; i<=n; ++i)
        if(v[i]) pv.push_back(i);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n; prime();

    if(n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    int st=0, en=0, sum=pv[0], ans=0;
    while(true) {
        if(sum < n) {
            en++;
            if(en >= pv.size()) break;
            sum += pv[en];
        }
        else {
            if(sum == n) ans += 1;
            sum -= pv[st];
            st++;
        }
    }

    cout << ans << '\n';
    
    return 0;
}