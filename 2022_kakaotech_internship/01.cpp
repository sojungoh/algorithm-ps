#include <string>
#include <vector>
#include <iostream>

using namespace std;

char type[4][2] = { {'R','T'},{'C','F'},{'J','M'},{'A','N'} };

int score(int choice) {
    if (choice < 4)
        return choice - 4;
    return choice % 4;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";

    int count[4] = {0, };

    for (int i = 0; i < survey.size(); i++) {
        if (survey[i][0] == 'R') {
            count[0] += score(choices[i]);
        }
        else if(survey[i][0] == 'T') {
           count[0] -= score(choices[i]);
        }
        else if (survey[i][0] == 'C') {
            count[1] += score(choices[i]);
        }
        else if (survey[i][0] == 'F') {
            count[1] -= score(choices[i]);
        }
        else if (survey[i][0] == 'J') {
           count[2] += score(choices[i]);
        }
        else if (survey[i][0] == 'M') {
            count[2] -= score(choices[i]);
        }
        else if (survey[i][0] == 'A') {
            count[3] += score(choices[i]);
        }
        else if (survey[i][0] == 'N') {
            count[3] -= score(choices[i]);
        }
    }

    for (int i = 0; i < 4; i++) {
        if (count[i] > 0)
            answer += type[i][1];
        else
            answer += type[i][0];
    }

    return answer;
}

//int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    vector<string> survey = { "TR", "RT", "TR" };
//    vector<int> choices = { 7, 1, 3 };
//
//    cout << solution(survey, choices) << '\n';
//
//    return 0;
//}