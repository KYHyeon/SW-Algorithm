// 200218
// 1541 잃어버린 괄호
// 그리디 알고리즘

#include <iostream>
#include <string>
#include <cmath>

using namespace std;
string expr;

int str_to_int(int start, int end) {
    int ret = 0;
    for (int i = start; i < end; ++i) {
        ret += (expr[i] - '0') * (int) pow(10, end - 1 - i);
    }
    return ret;
}

int main() {
    int start = 0, end, ret = 0, i;
    bool minus = false;

    cin >> expr;
    for (i = 0; i < expr.size(); ++i) {
        if (expr[i] < '0') {
            end = i;
            int v = str_to_int(start, end);
            start = i + 1;
            minus ? (ret -= v) : (ret += v);
            if (expr[i] == '-')
                minus = true;
        }
    }

    int v = str_to_int(start, i);
    minus ? (ret -= v) : (ret += v);

    cout << ret;
}