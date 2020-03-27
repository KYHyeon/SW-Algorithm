//2644 촌수계산

#include <iostream>
#include <queue>

using namespace std;

int n, m;
int src, dst;
int person[101][101];
int visited[101];

queue<int> q;
int x, y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> src >> dst >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        person[x][y] = 1;
        person[y][x] = 1;
    }

    visited[src] = 1;
    q.push(src);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == dst) {
            cout << visited[cur] - 1;
            return 0;
        }

        for (int i = 1; i <= 100; ++i) {
            if (person[cur][i] && !visited[i]) {
                visited[i] = visited[cur] + 1;
                q.push(i);
            }
        }
    }

    cout << -1;
    return 0;
}