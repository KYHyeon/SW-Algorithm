#include <iostream>
#include <algorithm>
using namespace std;

int N;
int P[10001];
int ans;
int calc[10001];


int solve(int n)
{
	if (calc[n - 1])
	{
		return calc[n - 1];
	}
	int price = P[n - 1];
	for (int i = 1; i <= n / 2; ++i)
	{
		price = max(price, solve(i) + solve(n - i));
	}
	return calc[n - 1] = price;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> P[i];
	}


	cout << solve(N);
}
