// 1373 2진수 8진수
// 문자열처리

#include <iostream>
#include <string>
#include <cmath>

using namespace std;
string s;

int calc(int start, int n) {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret += (s[start + i] - '0') * pow(2, n - i - 1);
    }
    return ret;
}

int main() {
    cin >> s;

    if (s[0] == '0')
        cout << '0';

    int front = calc(0, s.length() % 3);
    if (front)
        cout << front;

    for (int i = s.length() % 3; i < s.length(); i += 3) {
        cout << calc(i, 3);
    }
}