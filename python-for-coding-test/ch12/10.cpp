#include <string>
#include <vector>
#include <iostream>

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
    
    for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << key[i][j] << ' ';
		}
		cout << endl;
	}
}

bool docking(vector<vector<int>> v1, vector<vector<int>> v2) {
	
	int n, m, temp, count = 0;
    bool break_flag, ret_val = false;
    
	m = v1.size();
    n = v2.size();
    
    for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(v2[i][j] == 0) ++count;
    
    for(int k = 0; k < 4; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                
                break_flag = false;
                temp = 0;
                
                for(int a = i; a < n; ++a) {
                    if(a - i >= m) 
                        continue;
                    
                    for(int b = j; b < n; ++b) {
                        if(b - j >= m)
                            continue;
                        
                        if(v2[a][b] + v1[a - i][b - j] != 1) {
                            break_flag = true;
                            break;
                        }
                        
                        if(v2[a][b] == 0) ++temp;
                        
                    }
                    if(break_flag) break;
                }
                
                if(!break_flag && count == temp) {
                    ret_val = true;
                    break;
                }
            }
            if(ret_val) break;
        }
        if(ret_val) break;
        rotation_by_clockwise(v1);
    }
    
    return ret_val;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    answer = docking(key, lock) || docking(lock, key);
    
    return answer;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	vector<vector<int>> key = {{1,1,0},{0,0,1},{0,0,0}};
	vector<vector<int>> lock = {{1,1,1},{1,1,0},{1,0,1}};
	
	cout << solution(key, lock) << endl;
	
	
	return 0;
}
