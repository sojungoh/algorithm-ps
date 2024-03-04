// https://tech.kakao.com/2023/12/27/2024-coding-test-winter-internship/

#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int n = friends.size();
    
    int **present_info = new int*[n + 1];
    for(int i = 0; i <= n; ++i)
        present_info[i] = new int[n + 1];
    
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) {
            present_info[i][j] = 0;
        }
    }
    
    map<string, int> name_hash;
    for(int i = 0; i < n; ++i) {
        name_hash.insert({friends[i], i});
    }
    
    // calculate giving and receiving count
    for(auto s : gifts) {
        int idx = s.find(" ");
        int giver = name_hash[s.substr(0, idx)];
        int receiver = name_hash[s.substr(idx + 1)];
        
        present_info[giver][receiver] += 1;
    }
    
    // calculate 선물지수
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            present_info[i][n] += present_info[i][j];
            present_info[n][i] += present_info[j][i];
        }
    }
    
    vector<int> total_val;
    for(int i = 0; i < n; ++i)
        total_val.push_back(present_info[i][n] - present_info[n][i]);
    
    // next month present count
    int *present_count = new int[n];
    for(int i = 0; i < n; ++i)
        present_count[i] = 0;
    
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(present_info[i][j] > present_info[j][i]) {
                present_count[i] += 1;
            }
            else if(present_info[i][j] < present_info[j][i]) {
                present_count[j] += 1;
            }
            else if(total_val[i] > total_val[j]) {
                present_count[i] += 1;
            }
            else if(total_val[i] < total_val[j]) {
                present_count[j] += 1;
            }
        }
    }
    
    // get a max value of next month present count
    for(int i = 0; i < n; ++i)
        answer = max(answer, present_count[i]);
    
    return answer;
}