#include <iostream>
#include <memory.h>

using namespace std;

//Const Val
struct Point {
    int y, x;
};

void CycleUp();

void CycleDown();

enum Direction {
    UP, DOWN, LEFT, RIGHT
};

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

//Input Val
int R, C, T;
int A[51][51]; // 미세먼지 행렬
Point Cleaner[2];   //0: 위 공기 청정기 1: 아래 공기 청정기

//Temp Val
int nCleaner;   // 입력받은 공기청정기의 개수
int tmp[51][51];    //계산 중간에 사용하는 행렬


void Diffusion(int y, int x) {
    int val = A[y][x];
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        if (A[ny][nx] == -1) continue;

        tmp[ny][nx] += A[y][x] / 5;
        val -= A[y][x] / 5;
    }
    tmp[y][x] += val;
}

void Print() {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    cin >> R >> C >> T;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> A[i][j];
            if (A[i][j] == -1) {
                Cleaner[nCleaner++] = {i, j};
            }
        }
    }

    while (T--) {
        memset(tmp, 0, sizeof(tmp));
        //확산
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (A[i][j] > 0) {
                    Diffusion(i, j);
                }
            }
        }
//        cout << T << "확산\n";
//        Print();

        //순환
        CycleUp();
        CycleDown();

        for (auto &i : Cleaner) {
            tmp[i.y][i.x] = -1;
        }

        //복사
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                A[i][j] = tmp[i][j];
            }
        }
//        cout << T << "복사\n";
//        Print();
    }

    int ans = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            ans += A[i][j];
        }
    }
    cout << ans + 2;
}

void CycleUp() {
    Point current = Cleaner[0];
    Direction dir = RIGHT;

    int nVal;
    int cVal = 0;
    do {
        int nx = current.x;
        int ny = current.y;

        switch (dir) {
            case UP:
                ny--;
                break;
            case DOWN:
                ny++;
                break;
            case LEFT:
                nx--;
                break;
            case RIGHT:
                nx++;
                break;
        }

        if (ny < 0 || ny >= R || nx < 0 || nx >= C) {
            switch (dir) {
                case UP:
                    dir = LEFT;
                    ny++;
                    nx--;
                    break;
                case LEFT:
                    dir = DOWN;
                    nx++;
                    ny++;
                    break;
                case RIGHT:
                    dir = UP;
                    nx--;
                    ny--;
                    break;
                case DOWN:
                    dir = RIGHT;
                    ny--;
                    nx++;
                    break;
            }
        }
        nVal = tmp[ny][nx];
        tmp[ny][nx] = cVal;
        current = {ny, nx};
        cVal = nVal;

    } while (current.y != Cleaner[0].y || current.x != Cleaner[0].x);
}

void CycleDown() {
    Point current = Cleaner[1];
    Direction dir = RIGHT;

    int nVal;
    int cVal = 0;
    do {
        int nx = current.x;
        int ny = current.y;

        switch (dir) {
            case UP:
                ny--;
                break;
            case DOWN:
                ny++;
                break;
            case LEFT:
                nx--;
                break;
            case RIGHT:
                nx++;
                break;
        }

        if (ny < 0 || ny >= R || nx < 0 || nx >= C) {
            switch (dir) {
                case UP:
                    dir = RIGHT;
                    ny++;
                    nx++;
                    break;
                case LEFT:
                    dir = UP;
                    nx++;
                    ny--;
                    break;
                case RIGHT:
                    dir = DOWN;
                    nx--;
                    ny++;
                    break;
                case DOWN:
                    dir = LEFT;
                    ny--;
                    nx--;
                    break;
            }
        }
        nVal = tmp[ny][nx];
        tmp[ny][nx] = cVal;
        current = {ny, nx};
        cVal = nVal;

    } while (current.y != Cleaner[0].y || current.x != Cleaner[0].x);
}
