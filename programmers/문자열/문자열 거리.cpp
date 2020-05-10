#include <string>
#include <vector>
#include <algorithm>

// https://programmers.co.kr/skill_checks/129337?challenge_id=2579

using namespace std;

int answer = 9999999;
vector<int> check;

void dfs(string begin, string target, vector<string> &words, int n) {
    if (begin == target) {
        answer = min(answer, n);
        return;
    }

    for (int j = 0; j < words.size(); j++) {
        if (check[j]) continue;

        int cnt = 0;
        for (int i = 0; i < begin.length(); i++) {
            if (begin[i] != words[j][i])
                cnt++;
        }
        if (cnt == 1) {
            check[j] = 1;
            dfs(words[j], target, words, n + 1);
            check[j] = 0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    check.assign(words.size(), 0);
    dfs(begin, target, words, 0);
    if (answer == 9999999) return 0;
    return answer;
}