#include <iostream>
using namespace std;

int N, B, C;
int A[1000001];
long long ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	cin >> B >> C;
	for (int i = 0; i < N; ++i)
	{
		if (A[i] - B <= 0) //혼자서 모두 커버가 되는 경우
		{
			continue;
		}
		ans += (A[i] - B) / C;
		ans += (A[i] - B) % C != 0;
	}
	cout << ans + N;
}
