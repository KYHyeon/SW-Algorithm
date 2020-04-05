#include <iostream>
#include <vector>

using namespace std;

using matrix = vector<vector<int>>;
int N, M, K;
matrix notebook;
matrix sticker;

void rot90() {
    matrix ret(sticker[0].size(), vector<int>(sticker.size(), 0));
    for (int i = 0; i < sticker.size(); ++i) {
        for (int j = 0; j < sticker[0].size(); ++j) {
            ret[j][sticker.size() - 1 - i] = sticker[i][j];
        }
    }
    sticker.swap(ret);
}

int check(int i, int j) {
    for (int k = 0; k < sticker.size(); ++k) {
        if (i + k >= N) {
            return 0;
        }
        for (int l = 0; l < sticker[0].size(); ++l) {
            if (j + l >= M) {
                return 0;
            }
            if (sticker[k][l] && notebook[i + k][j + l]) {
                return 0;
            }
        }
    }
    return 1;
}

void tryStick() {
    for (int t = 0; t < 4; ++t) {
        for (int i = 0; i < notebook.size(); ++i) {
            for (int j = 0; j < notebook[0].size(); ++j) {
                if (check(i, j)) {
                    for (int k = 0; k < sticker.size(); ++k) {
                        for (int l = 0; l < sticker[0].size(); ++l) {
                            if (sticker[k][l]) {
                                notebook[i + k][j + l] = 1;
                            }
                        }
                    }
                    return;
                }
            }
        }
        rot90();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    notebook.assign(N, vector<int>(M, 0));

    for (int i = 0; i < K; ++i) {
        int R, C;
        cin >> R >> C;
        sticker.clear();
        for (int j = 0; j < R; ++j) {
            sticker.push_back(vector<int>());
            for (int k = 0; k < C; ++k) {
                int x;
                cin >> x;
                sticker[j].push_back(x);
            }
        }
        tryStick();
    }

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            sum += notebook[i][j];
        }
    }
    cout << sum;
}