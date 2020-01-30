#include<iostream>
#include <map>
#include <string>
using namespace std;

map<string, string> p;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	while (n--)
	{
		string id, pw;
		cin >> id >> pw;
		p[id] = pw;
	}
	while (m--)
	{
		string s;
		cin >> s;
		cout << p[s] << '\n';
	}
}
