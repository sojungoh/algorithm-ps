#include <string>
#include <vector>

using namespace std;

void rotation_by_clockwise(vector<vector<int>>& key) {
    int n = key.size();
    vector<vector<int>> rot_key(n);
    
    for(int i = 0; i < n; ++i) {
        for(int j = 1; j <= n; ++j) {
            rot_key[i].push_back(key[n - j][i]);
        }
    }
    
    key = rot_key;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
			
    int n, m, temp, count = 0;
    bool break_flag;
    
    m = key.size();
    n = lock.size();
    
    for(int i = 0; i < n; ++i)
    	for(int j = 0; j < n; ++j)
		if(lock[i][j] == 0) ++count;
			
    for(int k = 0; k < 4; ++k) {
        for(int i = -m + 1; i < n; ++i) {
            for(int j = -m + 1; j < n; ++j) {
                
                break_flag = false;
                temp = 0;
                
                for(int a = 0; a < n; ++a) {
                    if(a < i || a - i >= m) 
                        continue;
                    
                    for(int b = 0; b < n; ++b) {
                        if(b < j || b - j >= m)
                            continue;
                        
                        if(lock[a][b] + key[a - i][b - j] != 1) {
                            break_flag = true;
                            break;
                        }
                        
			if(lock[a][b] == 0) ++temp;
                    }
                    if(break_flag) break;
                }
                
                if(!break_flag && count == temp) {
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
