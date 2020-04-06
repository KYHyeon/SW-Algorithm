// 1748 수 이어쓰기

#include <iostream>
#include <cmath>

using namespace std;
int N;
long long ans;

int main() {
    cin >> N;
//    1 * 1 ~ 9
//    2 * 10 ~ 99
//    3 * 100 ~ 999
//    n * 10^(n-1) ~ 10^n-1
    int n = 0;
    while (++n) {
        long long start = pow(10, n - 1);
        long long end = pow(10, n) - 1;
        if (N <= end) {
            ans += n * ((N - start) + 1);
            break;
        }
        ans += n * (end - start + 1);
    }
    cout << ans;
}