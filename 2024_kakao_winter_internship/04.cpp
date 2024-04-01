#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(int coin, vector<int> cards) {
    int answer = 0;
    int n = cards.size();
    int round = n / 3;

    vector<bool> cur_cards(n + 1, false);
    vector<bool> next_cards(n + 1, false);

    for(int i = 0; i < round; ++i)
        cur_cards[cards[i]] = true;

    int r = 0;
    for(; r < round; ++r) {
        bool cont_flag = false;
        answer += 1;
        
        int tmp[2] = {cards[2*r + round], cards[2*r + round + 1]};
        for(int i = 0; i < 2; ++i)
            next_cards[tmp[i]] = true;

        // 동전 0
        for(int c = 1; c < n + 1; ++c) {
            if(!cur_cards[c])
                continue;
            int k = n + 1 - c;

            if(cur_cards[c] && cur_cards[k]) {
                cur_cards[c] = false;
                cur_cards[k] = false;
                cont_flag = true;
                break;
            }
        }

        if(cont_flag)
            continue;

        // 동전 1
        if(coin < 1)
            break;
        
        for(int c = 1; c < n + 1; ++c) {
            if(!next_cards[c])
                continue;
            
            int k = n + 1 - c;

            if(cur_cards[k]) {
                coin -= 1;
                cur_cards[k] = false;
                next_cards[c] = false;
                cont_flag = true;
                break;
            }
        }

        if(cont_flag)
            continue;

        // 동전 2
        if(coin < 2)
            break;
        
        for(int c = 1; c < n + 1; ++c) {
            if(!next_cards[c])
                continue;
            int k = n + 1 - c;

            if(next_cards[c] && next_cards[k]) {
                coin -= 2;
                next_cards[c] = false;
                next_cards[k] = false;
                cont_flag = true;
                break;
            }
        }

        if(!cont_flag)
            break;
    }

    if(r == round)
        answer += 1;

    return answer;
}