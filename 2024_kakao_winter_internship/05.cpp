#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    int answer = 0;
    
    vector<int> a(n, 0);
    vector<int> b(n, 0);

    a[0] = 1;
    b[0] = (tops[0] == 1) ? 3 : 2;
    for(int i = 1; i < n; ++i) {
        a[i] = (a[i - 1] + b[i - 1]) % 10007;
        b[i] = (tops[i] == 1) ? (2*(a[i - 1] + b[i - 1])) % 10007 + b[i - 1] : (a[i - 1] + b[i - 1]) % 10007 + b[i - 1];
    }

    answer = (a[n - 1] + b[n - 1]) % 10007;
    
    return answer;
}