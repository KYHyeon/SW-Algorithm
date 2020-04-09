// 1016 제곱 ㄴㄴ 수

#include <iostream>
using namespace std;

bool sieve[1000001];
long long n, x;

int main() {
    cin >> n >> x;

    for (long long i = 2; i * i <= x; i++){
        long long start = n / (i * i);
        if (start * i * i != n) start++;
        for (long long j = start; i * i * j <= x; j++) {
            sieve[i * i * j - n] = true;
        }
    }
    int count = 0;
    for (int i = 0; i < x - n + 1; i++) {
        if (!sieve[i]) count++;
    }
    cout << count << '\n';

    return 0;
}
