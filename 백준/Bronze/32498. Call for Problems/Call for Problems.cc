#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);
	int N;
	cin >> N;
	int a;
	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> a;

		if (a % 2 == 1) {
			ans ++;
		}
	}

	cout << ans;

	return 0;
}