#include <iostream>
#include <algorithm>

using namespace std;

int x, y;

bool solve() {
    int k = 1;
    int s = 0;

    if(x > y) swap(x, y);
    
    if(y == 0) {
        return true;
    }

    while(y >= k*3) {
        k *= 3;
        s++;
    }

    for(int i = s; i >= 0; --i, k/=3) {
        //cout << x << ' ' << y << '\n';

        if(y >= x) y -= k;
        else x -= k;
    }

    return (x == 0 && y == 0) ? true : false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> x >> y;
    cout << solve() << '\n';

    return 0;
}