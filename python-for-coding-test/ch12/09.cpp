#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string s) {
    int answer = 1000;
    
    if(s.length() == 1)
        return 1;
    
    string cur, next;
    
    for(int i = 1; i <= s.length() / 2; ++i) {
        int idx = 0;
        cur = s.substr(0, i);
        
        int count = 1, temp = 0;
        
        while((idx += i) < s.length()) {
            next = s.substr(idx, i);
            
            if(cur == next)
                count++;
            else {
                if(count != 1)
                    temp += to_string(count).length();
                temp += i;
                count = 1;
                cur = next;
            }
        }
        
        if(count != 1)
            temp += to_string(count).length();
        temp += cur.length();
        
        answer = min(temp, answer);
    }
    
    return answer;
}
