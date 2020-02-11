#include <iostream>
#include <cstring>
#include <vector>
#include <utility>

using namespace std;

int N;
vector<pair<int, int> > tree[100002];
int visited[100002];

//가장 먼 점을 찾는다 return {idx, dis};
pair<int, int> dfs(int n) {
    visited[n] = 1;
    int dis = 0;
    int idx = n;
    for (auto &p : tree[n]) {
        if (p.second && visited[p.first] == 0) {
            visited[p.first] = 1;
            pair<int, int> ret = dfs(p.first);
            if (dis < p.second + ret.second) {
                dis = p.second + ret.second;
                idx = ret.first;
            }
        }
    }
    return {idx, dis};
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int n, o, d;
        cin >> n;
        while (true) {
            cin >> o;
            if (o == -1) break;
            cin >> d;

            tree[n].emplace_back(o, d);
            tree[o].emplace_back(n, d);
        }
    }

    int idx = dfs(1).first;
    memset(visited, 0, sizeof visited);
    cout << dfs(idx).second;
}