#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 9;
    
    sort(dist.begin(), dist.end());
    
    do {
        // checking wall by clockwise
        for(int i = 0; i < weak.size(); ++i) {
            
            vector<int> temp;
            
            for(int k = 0; k < weak.size(); ++k) {
                if(i <= k)
                    temp.push_back(weak[k]);
                else
                    temp.push_back(weak[k] + n);
            }
            
            sort(temp.begin(), temp.end());
            
            auto iter = temp.begin();
            
            for(int j = 0; j < dist.size(); ++j) {
                int next = *iter + dist[j];
                
                iter = upper_bound(temp.begin(), temp.end(), next);
                
                if(iter == temp.end()) {
                    answer = min(answer, j + 1);
                    break;
                }
            }
        }
        
        // checking wall by counter clockwise
        for(int i = weak.size() - 1; i >= 0; --i) {
            
            vector<int> temp;
            
            for(int k = weak.size() - 1; k >= 0; --k) {
                if(i >= k)
                    temp.push_back(weak[k]);
                else
                    temp.push_back(weak[k] - n);
            }
            
            sort(temp.begin(), temp.end(), greater<>());
            
            auto iter = temp.begin();
            
            for(int j = 0; j < dist.size(); ++j) {
                int next = *iter - dist[j];
                
                for(; iter != temp.end(); ++iter)
                    if(*iter < next)
                        break;
                
                if(iter == temp.end()) {
                    answer = min(answer, j + 1);
                    break;
                }
            }
        }
    }while(next_permutation(dist.begin(), dist.end()));
    
    if(answer == 9)
        answer = -1;
    
    return answer;
}
