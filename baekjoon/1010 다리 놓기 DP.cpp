// 다리 놓기 1010 DP
#include <iostream>

using namespace std;
int N, M;
int memo[31][31];

int solve(int n, int m) {
    if (memo[n][m])
    {
        return memo[n][m];
    }
    if (n > m) {
        return 0;
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return m;
    }
    int ans = 0;
    for (int i = 1; i < m; ++i) {
        ans += solve(n - 1, m - i);
    }
    return memo[n][m] = ans;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N >> M;
        cout << solve(N, M) << '\n';
    }
}