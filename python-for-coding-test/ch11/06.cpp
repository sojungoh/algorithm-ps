#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<pair<int, int>> pq;
vector<int> index;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long sum = 0;
    
    for(int i = 0; i < food_times.size(); ++i) {
        pq.push({-food_times[i], i + 1});
        sum += food_times[i];
    }
    
    if(sum <= k)
        return -1;
    
    long long prev = 0;
    int sz = pq.size();
    
    while(!pq.empty()) {
        int x = -pq.top().first;
        
        if(k - sz * (x - prev) < 0)
            break;
        
        k -= sz * (x - prev);
        prev = x;
        sz -= 1;
        pq.pop();
    }
    
   while(!pq.empty()) {
       index.push_back(pq.top().second);
       pq.pop();
   }
    
    sort(index.begin(), index.end());
    
    answer = index[k % index.size()];
    
    return answer;
}
