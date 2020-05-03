#include <iostream>
#include <string>

using namespace std;

int T;
string s;

int solve(int n) {
    if (s.length() <= n) return 1;

    if (s[n] == '1') {
        //case 1
        if (s.length() <= n + 3)
            return 0;
        if (s[n + 1] != '0')
            return 0;
        if (s[n + 2] != '0')
            return 0;

        int m = n + 3;

        while (s[m] == '0') {
            if (m + 1 >= s.length()) return 0;
            else m++;
        }
        while (s[m] == '1') {
            if (m + 1 > s.length()) return 0;
            else if (m + 1 == s.length() || solve(m + 1))
                return 1;
            else m++;
        }

        return solve(m);
    } else {
        //case 2
        if (s[n + 1] == '1') {
            return solve(n + 2);
        } else {
            return 0;
        }
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> s;
        if (solve(0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
