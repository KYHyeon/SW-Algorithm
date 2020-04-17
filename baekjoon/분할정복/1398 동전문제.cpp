#include <iostream>
#include <algorithm>
using namespace std;

int Solve(int n)
{
	int ans = 999999;
	if (n >= 25)
	{
		ans = min(ans, 1 + Solve(n - 25));
	}

	int a = 0;
	a += n % 10;
	a += n / 10;
	ans = min(a, ans);
	return ans;
}


int main()
{

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int ans = 0;
		long long price;
		cin >> price;
		while (price)
		{
			ans += Solve(price % 100);
			price /= 100;
		}
		cout << ans << endl;
	}
}
