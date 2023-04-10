#include <string>
#include <vector>

using namespace std;

void rotation_by_clockwise(vector<vector<int>>& key) {
    int n = key.size();
    vector<vector<int>> rot_key(n);
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < n; ++j) {
            rot_key[i - 1].push_back(key[n - i][j]);
        }
    }
    
    key = rot_key;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    int n = lock.size();
    int m = key.size();
    
    bool break_flag;
    
    for(int k = 0; k < 4; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                
                break_flag = false;
                
                for(int a = 0; a < m; ++a) {
                    for(int b = 0; b < m; ++b) {
                        if(a < i || b < j || a + i >= m || b + j >= m)
                            continue;
                        
                        if(lock[i][j] + key[a - i][b - j] != 1) {
                            break_flag = true;
                            break;
                        }
                    }
                    if(break_flag) break;
                }
                
                if(!break_flag) {
                    answer = true;
                    break;
                }
            }
            if(answer) break;
        }
        if(answer) break;
        rotation_by_clockwise(key);
    }
    
    return answer;
}
