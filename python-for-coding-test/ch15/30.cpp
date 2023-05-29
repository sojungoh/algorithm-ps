#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int match = 0;

void binary_search(vector<pair<string, int>>& words, string query, int length, int start, int end) {
    if(start > end)
        return;
    
    int mid = (start + end) / 2;
    
    if(words[mid].first.compare(query) == 0) {
        if(words[mid].second == length)
            match += 1;
        binary_search(words, query, length, mid + 1, end);
        binary_search(words, query, length, start, mid - 1);   
    }
    else if(words[mid].first.compare(query) < 0) {
        binary_search(words, query, length, mid + 1, end);
    }
    else {
        binary_search(words, query, length, start, mid - 1);
    }
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    size_t n = words.size() - 1;
    
    for(string query : queries) {
        size_t l = query.length();
        int start_idx = l, end_idx = -1;
        
        for(int i = 0; i < l; ++i) {
            if(query[i] != '?') {
                start_idx = min(start_idx, i);
                end_idx = max(end_idx, i);
            }
        }
        
        match = 0;
        
        if(start_idx == l && end_idx == -1) {
			for(string word: words) {
				if(word.length() == l)
					match += 1;
			}
			answer.push_back(match);
			continue;
		}
        
        vector<pair<string, int>> sub_words;
        
        for(string word : words) {
            if(start_idx < word.length() && end_idx < word.length()) {
                string s = word.substr(start_idx, end_idx + 1);
                sub_words.push_back({s, word.length()});   
            }
        }
        
        sort(sub_words.begin(), sub_words.end());
        
        binary_search(sub_words, query.substr(start_idx, end_idx + 1), l, 0, sub_words.size() - 1);
        
        answer.push_back(match);
    }
    
    return answer;
}
