#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

priority_queue<pair<double, int>> pq;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    int * count_stages = new int[N + 2];
    
    for(int i = 0; i < N + 2; ++i)
        count_stages[i] = 0;
    
    for(int s : stages)
        count_stages[s] += 1;
    
    int num_of_users = stages.size();
    
    for(int i = 1; i < N + 1; ++i) {
        double failure = (double)count_stages[i] / (double)num_of_users;
        pq.push({failure, -i});
        num_of_users -= count_stages[i];
        
        if(num_of_users == 0) {
            while(++i != N + 1) {
                pq.push({0, -i});
            }
        }
    }
    
    while(!pq.empty()) {
        answer.push_back(-pq.top().second);
        pq.pop();
    }
    
    return answer;
}
