//18809 Gaaaaaaaaaarden
//DFS / BFS

#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int N, M, G, R;
int garden[51][51];
int select_rg[51][51];
int select_r[51][51];
pair<int, int> visit[51][51]; //{색깔, 시간}
queue<pair<pair<int, int>, int>> rq;
queue<pair<pair<int, int>, int>> gq;
int ans;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
    int t = 0;
    int res = 0;
    while (++t) {
        while (!rq.empty() && rq.front().second < t) {
            pair<int, int> r = rq.front().first;
            rq.pop();
            if (visit[r.first][r.second].first == 3) {
                // 초록색이 뒤늦게 와서 꽃이 된 경우
                continue;
            }
            for (int i = 0; i < 4; ++i) {
                int nx = r.second + dx[i];
                int ny = r.first + dy[i];

                if (nx < 0 || nx >= M) continue;
                if (ny < 0 || ny >= N) continue;
                if (garden[ny][nx] == 0) continue;  // 물 인 경우
                if (visit[ny][nx].first > 0) continue;// 이미 배양액 또는 꽃 있는 경우

                visit[ny][nx] = {1, t};
                rq.push({{ny, nx}, t});
            }
        }

        while (!gq.empty() && gq.front().second < t) {
            pair<int, int> g = gq.front().first;
            gq.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = g.second + dx[i];
                int ny = g.first + dy[i];

                if (nx < 0 || nx >= M) continue;
                if (ny < 0 || ny >= N) continue;
                if (garden[ny][nx] == 0) continue;  // 물 인 경우
                if (visit[ny][nx].first >= 2) continue;// 꽃이나 초록색 배양액이 있는 경우
                if (visit[ny][nx].first == 1) {
                    // 빨간색 배양액이 있는 경우
                    if (visit[ny][nx].second == t) {
                        visit[ny][nx] = {3, t};
                        res++;
                        continue;
                    } else {
                        continue;
                    }
                }

                visit[ny][nx] = {2, t};
                gq.push({{ny, nx}, t});
            }
        }

        if (rq.empty() || gq.empty()) {
            ans = max(res, ans);
            return;
        }
    }
}

void clear(queue<pair<pair<int, int>, int>> &q) {
    queue<pair<pair<int, int>, int>> empty;
    swap(q, empty);
}

void selectRed(int r, int i, int j) {
    if (!r) {
        clear(rq);
        clear(gq);
        for (int k = 0; k < N; ++k) {
            for (int l = 0; l < M; ++l) {
                visit[k][l] = {0, 0};
            }
        }
        for (i = 0; i < N; ++i) {
            for (j = 0; j < M; ++j) {
                if (select_rg[i][j]) {
                    if (select_r[i][j]) {
                        rq.push({{i, j}, 0});
                        visit[i][j] = {1, 0};
                    } else {
                        gq.push({{i, j}, 0});
                        visit[i][j] = {2, 0};
                    }
                    if (rq.size() + gq.size() == G + R) {
                        solve();
                        return;
                    }
                }
            }
        }
        return;
    }
    if (j >= M) {
        i++;
        j = 0;
    }
    for (; i < N; ++i) {
        for (; j < M; ++j) {
            if (select_rg[i][j] == 1 && select_r[i][j] == 0) {
                select_r[i][j] = 1;
                selectRed(r - 1, i, j);
                select_r[i][j] = 0;
            }
        }
        j = 0;
    }
}

void init(int n, int i, int j) {
    if (!n) {
        selectRed(R, 0, 0);
        return;
    }
    if (j >= M) {
        i++;
        j = 0;
    }
    for (; i < N; ++i) {
        for (; j < M; ++j) {
            if (garden[i][j] == 2 && select_rg[i][j] == 0) {
                select_rg[i][j] = 1;
                init(n - 1, i, j + 1);
                select_rg[i][j] = 0;
            }
        }
        j = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> G >> R;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> garden[i][j];
        }
    }
    init(R + G, 0, 0);
    cout << ans;
}