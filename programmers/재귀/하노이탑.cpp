// 하노이탑
// https://programmers.co.kr/skill_checks/129337?challenge_id=885

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void move(int n, int from, int by, int to) {
    if (!n) return;
    
    move (n-1, from, to, by);
    
    vector<int> v;
    v.push_back(from);
    v.push_back(to);

    answer.push_back(v);
    
    move (n-1, by, from, to);
}

vector<vector<int>> solution(int n) {
    move(n, 1, 2, 3);
    return answer;
}