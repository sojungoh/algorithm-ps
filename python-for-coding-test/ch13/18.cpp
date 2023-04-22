#include <string>
#include <vector>

using namespace std;

string get_correct_string(string p) {
    string u = "", v = "";
    int left = 0, right = 0;
    bool flag = false;
    
    int i = 0;
    for(; i < p.length(); ++i) {
        if(p[i] == '(')
            left += 1;
        else if(p[i] == ')')
            right += 1;
        
        if(right > left)
            flag = true;
        
        if(left == right)
            break;
    }
    
    if(i == p.length())
        return "";
    
    u = p.substr(0, i + 1);
    v = p.substr(i + 1);
    
    if(!flag) {
        u += get_correct_string(v);
        return u;
    }
    else {
        string tmp = "(" + get_correct_string(v) + ")";
        
        for(int i = 1; i < u.length() - 1; ++i) {
            if(u[i] == '(')
                tmp += ')';
            else
                tmp += '(';
        }
        return tmp;
    }
}

string solution(string p) {
    string answer = "";
    
    answer = get_correct_string(p);
    
    return answer;
}
