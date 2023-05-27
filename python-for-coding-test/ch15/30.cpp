#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int match = 0;
vector<int> word_index(10001);

void binary_search(vector<string>& words, string query, int start, int end) {
    if(start > end)
        return;
    
    int mid = (start + end) / 2;
    
    if(words[mid].compare(query) == 0) {
        match += 1;
        binary_search(words, query, mid + 1, end);
        binary_search(words, query, start, mid - 1);
    }
    else if(words[mid].compare(query) < 0) {
        binary_search(words, query, mid + 1, end);
    }
    else {
        binary_search(words, query, start, mid - 1);
    }
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    size_t n = words.size() - 1;
    
    for(int i = 0; i <= n; ++i) {
        
    }
    
    int max_idx = -1, min_idx = n + 1;
    for(string query : queries) {
        match = 0;
        
        for(int i = 0; i < query.length(); ++i) {
            if(c == '?') {
                max_idx = max(max_idx, i);
                min_idx = min(min_idx, i);
            }
        }
        
        
        
        binary_search(words, query, 0, n);
        answer.push_back(match);
    }
    
    return answer;
}
