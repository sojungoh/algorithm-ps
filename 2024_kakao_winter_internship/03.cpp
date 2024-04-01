#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<vector<int>> dice_cp;
vector<vector<int>> combi;

// 주어진 조합으로 구할 수 있는 주사위 합 경우의 수 -> 최대 6^5 <= 8000
void sum_dice(const vector<int>& v, vector<int>& tmp, int cnt, int sum, int n) {
    if(cnt == n) {
        tmp.push_back(sum);
        return;
    }

    for(int j = 0; j < 6; ++j) {
        sum += dice_cp[v[cnt] - 1][j];
        sum_dice(v, tmp, cnt + 1, sum, n);
        sum -= dice_cp[v[cnt] - 1][j];
    }
}

// 주사위 번호 조합 구하기 -> 최대 10C5=252
void picking_dice(vector<int> v, int i, int n) {
    if(v.size() == n) {
        combi.push_back(v);
        return;
    }

    for(int k = i; k <= 2*n; ++k) {
        v.push_back(k);
        picking_dice(v, k + 1, n);
        v.pop_back();
    }
}

vector<int> solution(vector<vector<int>> dice) {
    dice_cp = dice;
    int n = dice.size();
    int hn = n / 2;

    vector<int> answer;
    int max_win_cnt = 0;

    vector<int> tmp;
    picking_dice(tmp, 1, hn);
    
    // combi 조합 인덱스 합이 nChn - 1 이 되면 중복 없이 분할된 두 개의 집합
    int start = 0;
    int end = combi.size() - 1;
    while(start < end) {
        vector<int> arr1, arr2;
        sum_dice(combi[start], arr1, 0, 0, hn);
        sum_dice(combi[end], arr2, 0, 0, hn);

        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        int win_cnt1 = 0, win_cnt2 = 0;
        for(int a : arr1) {
            int w = lower_bound(arr2.begin(), arr2.end(), a) - arr2.begin();
            if(w > 1)
                win_cnt1 += w;
        }

        for(int a : arr2) {
            int w = lower_bound(arr1.begin(), arr1.end(), a) - arr1.begin();
            if(w > 1)
                win_cnt2 += w;
        }

        if(win_cnt1 > win_cnt2) {
            if(max_win_cnt < win_cnt1) {
                max_win_cnt = win_cnt1;
                answer = combi[start];
            }
        }
        else if(win_cnt1 < win_cnt2) {
            if(max_win_cnt < win_cnt2) {
                max_win_cnt = win_cnt2;
                answer = combi[end];
            }
        }
        start++;
        end--;
    }

    return answer;
}