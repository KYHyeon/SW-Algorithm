// 다리 놓기 1010 DFS
// 20.01.30
// 시간초과
#include <iostream>

using namespace std;
int visit[31];
int cnt;
int N, M;

void clear() {
    for (int &i : visit) {
        i = 0;
    }
    cnt = 0;
}

void solve(int n, int start) {
    if (start > M) {
        return;
    }
    if (n == 0) {
        cnt++;
    } else {
        for (int i = start; i < M; ++i) {
            if (visit[i] == 0) {
                visit[i] = 1;
                solve(n - 1, i + 1);
                visit[i] = 0;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N >> M;
        solve(N, 0);
        cout << cnt << '\n';
        clear();
    }
}