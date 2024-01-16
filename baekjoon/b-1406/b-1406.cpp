#include <iostream>
#include <list>
#include <string>

using namespace std;

list<char> parsing(const string& s) {
    list<char> l;
    for(int i = 0; i < s.size(); ++i)
        l.push_back(s[i]);
    return l;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;
    list<char> l = parsing(s);
    list<char>::iterator it = l.end();

    int m; cin >> m;
    char c;
    while(m--) {
        cin >> c;

        if(c == 'L') { if(it != l.begin()) it--; }
        else if(c == 'D') { if(it != l.end()) it++; }
        else if(c == 'B') { if(it != l.begin()) it = l.erase(--it); }
        else if(c == 'P') { cin >> c; l.insert(it, c); }
    }

    for(char ans : l)
        cout << ans;
    cout << '\n';

    return 0;
}