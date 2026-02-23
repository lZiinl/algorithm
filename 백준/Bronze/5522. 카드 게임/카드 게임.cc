#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);
	int a;
	int ans = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		ans += a;
	}

	cout << ans;

	return 0;
}