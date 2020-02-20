// 16235 나무재테크
// 20.02.21 deque

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int diff[8][2] = {{-1, -1},
                  {-1, 0},
                  {-1, 1},
                  {0,  -1},
                  {0,  1},
                  {1,  -1},
                  {1,  0},
                  {1,  1}};

int A[11][11];
int map[11][11];
deque<int> trees[101][101];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            map[i][j] = 5;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < M; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        trees[x - 1][y - 1].push_back(z);
    }

    for (int y = 0; y < K; ++y) {
        //가을에 번식하는 나무들
        vector<pair<int, int>> breeds;
        //여름에 죽는 나무들
        vector<pair<int, pair<int, int>>> deadTrees;

        //봄
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                int len = trees[i][j].size();
                for (int k = 0; k < len; ++k) {
                    int age = trees[i][j].front();
                    trees[i][j].pop_front();

                    if (map[i][j] >= age) {
                        map[i][j] -= age++;

                        if (age % 5 == 0) {
                            breeds.emplace_back(i, j);
                        }

                        trees[i][j].push_back(age);
                    } else {
                        deadTrees.push_back({age, {i, j}});
                    }
                }
            }
        }
        //여름
        for (auto deadTree : deadTrees) {
            map[deadTree.second.first][deadTree.second.second] += deadTree.first / 2;
        }

        //가을
        for (auto breed : breeds) {
            for (auto &k : diff) {
                int nx = breed.first + k[0];
                int ny = breed.second + k[1];
                if (0 > nx || nx >= N || 0 > ny || ny >= N) {
                    continue;
                }
                trees[nx][ny].push_front(1);
            }
        }

        //겨울
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                map[i][j] += A[i][j];
            }
        }
    }

    int ans = 0;
    for (auto &tree : trees) {
        for (const auto &j : tree) {
            ans += j.size();
        }
    }
    cout << ans;
}