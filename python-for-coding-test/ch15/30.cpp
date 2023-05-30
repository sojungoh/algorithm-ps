#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int first_idx, last_idx;
vector<vector<string>> words_by_length(10001);
vector<vector<string>> reverse_words_by_length(10001);
bool is_vec_sorted[10001][2] = {0, };
unordered_map<string, int> query_table;

string reverse_word(string word) {
    string rword = "";
    
    for(int i = word.length() - 1; i >= 0; --i)
        rword += word[i];
    
    return rword;
}

void binary_search(vector<string>& vec, string query, int start, int end) {
    if(start > end)
        return;
    
    int mid = (start + end) / 2;
    string s = vec[mid].substr(0, query.length());
    
    if(s.compare(query) == 0) {
        first_idx = min(first_idx, mid);
        last_idx = max(last_idx, mid);
    }
    
    if(s.compare(query) <= 0)
        binary_search(vec, query, mid + 1, end);
    if(s.compare(query) >= 0)
        binary_search(vec, query, start, mid - 1);
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    for(string word : words) {
        words_by_length[word.length()].push_back(word);
        string rword = reverse_word(word);
        reverse_words_by_length[word.length()].push_back(rword);
    }
    
    for(string query : queries) {
        // 효율성 1번 테스트  - 검색어 중복 시간초과 방지
        if(query_table.find(query) != query_table.end()) {
            answer.push_back(query_table[query]);
            continue;
        }
        
        size_t l = query.length();
        
        first_idx = l;
        last_idx = -1;
        
        for(int i = 0; i < l; ++i) {
            if(query[i] != '?') {
                first_idx = min(first_idx, i);
                last_idx = max(last_idx, i);
            }
        }
        // 검색 키워드 전체가 물음표일 시 바로 리턴
        if(first_idx == l && last_idx == -1) {
            answer.push_back(words_by_length[l].size());
            continue;
        }
        
        bool first = (first_idx == 0) ? true : false; // 접두사, 접미사 체크
	// 물음표를 제외한 검색 키워드 추출
        string sub_query = query.substr(first_idx, last_idx - first_idx + 1);
        string reverse_sub_query = reverse_word(sub_query);
        
        first_idx = 100001;
        last_idx = -1;
        
        if(first) {
	    // 중복 sort 방지
            if(!is_vec_sorted[l][0]) {
                sort(words_by_length[l].begin(), words_by_length[l].end());
                is_vec_sorted[l][0] = 1;
            }
            
            binary_search(words_by_length[l], sub_query, 0, words_by_length[l].size() - 1);
        }
        else {
            if(!is_vec_sorted[l][1]) {
                sort(reverse_words_by_length[l].begin(), reverse_words_by_length[l].end());
                is_vec_sorted[l][1] = 1;
            }
            binary_search(reverse_words_by_length[l], reverse_sub_query, 0, reverse_words_by_length[l].size() - 1);
        }
        
        int val;
        
        if(last_idx < first_idx)
            val = 0;
        else
            val = last_idx - first_idx + 1;
        
        query_table.insert({query, val});
        answer.push_back(val);
    }
    
    return answer;
}
