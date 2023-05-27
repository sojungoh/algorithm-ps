#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int match = 0;

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
    
    sort(words.begin(), words.end());
    
    for(string query : queries) {
        match = 0;
        binary_search(words, query, 0, n);
        answer.push_back(match);
    }
    
    return answer;
}
