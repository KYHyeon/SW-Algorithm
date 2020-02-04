#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int S[21][21];
int team[21];

vector<int> tStart;
vector<int> tLink;

int ans = 1987654321;

void calc_score() {
    int sc0 = 0;
    for (int i = 0; i < tStart.size(); ++i) {
        for (int j = i + 1; j < tStart.size(); ++j) {
            sc0 += S[tStart[i]][tStart[j]];
            sc0 += S[tStart[j]][tStart[i]];
        }
    }

    int sc1 = 0;
    for (int i = 0; i < tLink.size(); ++i) {
        for (int j = i + 1; j < tLink.size(); ++j) {
            sc1 += S[tLink[i]][tLink[j]];
            sc1 += S[tLink[j]][tLink[i]];
        }
    }

    ans = min(ans, abs(sc0 - sc1));
}

void make_team(int n, int start) {
    //DFS로 경우의 수 계산
    if (n) {
        for (int i = start; i < N; ++i) {
            if (team[i] == 0) {
                team[i] = 1;
                make_team(n - 1, i + 1);
                team[i] = 0;
            }
        }
    } else {
        //모든 선수 팀에 배치하였을 경우
        //점수 계산
        tStart.clear();
        tLink.clear();
        for (int i = 0; i < N; ++i) {
            if (team[i] == 0) {
                tStart.push_back(i);
            } else {
                tLink.push_back(i);
            }
        }
        calc_score();
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> S[i][j];
        }
    }

    make_team(N / 2, 0);
    cout << ans;
}