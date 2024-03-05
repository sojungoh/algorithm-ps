#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    answer.resize(4);
    for(int i = 0; i < 4; ++i)
        answer[i] = 0;
    
    int max_node = 0;
    for(auto e : edges) {
        int tmp = max(e[0], e[1]);
        max_node = max(max_node, tmp);
    }
   
    vector<int> in(max_node + 1, 0);
    vector<int> out(max_node + 1, 0);
    vector<vector<int>> graph(max_node + 1);
    for(auto e : edges) {
        in[e[1]] += 1;
        out[e[0]] += 1;
        graph[e[0]].push_back(e[1]);
    }
    
    int g_count = 0;
    for(int i = 1; i <= max_node; ++i) {    
        if(in[i] == 0 && out[i] > 1) {
            answer[0] = i;
            g_count = out[i];
            for(int v : graph[i])
                in[v] -= 1;
            in[i] = -1;
            out[i] = -1;
            break;
        }
    }
    
    for(int i = 1; i <= max_node; ++i) {
        if(in[i] > 1) {
            answer[3] += 1;
        }
        else if(in[i] == 0)
            answer[2] += 1;
    }
    answer[1] = g_count - answer[2] - answer[3];
    
    return answer;
}