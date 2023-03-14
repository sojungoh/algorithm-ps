#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

#define pii pair<int, int>

long long k;
vector<int> food_times;
vector<int> answer_v;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long sum = 0;
    int sz = food_times.size();

    for (int i = 0; i < sz; i++) {
        pq.push(pii(food_times[i], i + 1));
        sum += food_times[i];
    }

    if (sum <= k)
        answer = -1;
    else {
        sum = 0;
        while (!pq.empty()) {
            if (k - (pq.top().first - sum) * sz < 0)
                break;

            k -= (pq.top().first - sum) * sz;

            long long temp = pq.top().first - sum;
            sum += temp;
            --sz;
            pq.pop();
        }

        while (!pq.empty()) {
            answer_v.push_back(pq.top().second);
            pq.pop();
        }
        sort(answer_v.begin(), answer_v.end());

        answer = answer_v[k % answer_v.size()];
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int time;

    cin >> k;

    do {
        cin >> time;
        food_times.push_back(time);
    } while (getc(stdin) == ' ');

    cout << solution(food_times, k) << '\n';

    return 0;
}