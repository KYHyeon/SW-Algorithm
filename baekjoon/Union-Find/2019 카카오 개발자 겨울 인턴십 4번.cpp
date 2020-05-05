//https://tech.kakao.com/2020/04/01/2019-internship-test/
//https://programmers.co.kr/learn/courses/30/lessons/64063

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
unordered_map<long long, long long> parent;

long long Find(long long n) {
    if (parent[n] == 0) {
        return n;
    } else {
        return parent[n] = Find(parent[n]);
    }
}

void Union(long long n, long long m) {
    long long pn = Find(n);
    long long pm = Find(m);

    long long M = min(pn, pm);
    long long X = pn == M ? m : n;
    parent[M] = X;
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    for (long long i : room_number) {
        long long x = Find(i);
        Union(x, x + 1);
        answer.push_back(x);
    }

    return answer;
}

int main() {
    long long k = 10;
    vector<long long> room_number = {1, 3, 4, 1, 3, 1};
    solution(k, room_number);
}