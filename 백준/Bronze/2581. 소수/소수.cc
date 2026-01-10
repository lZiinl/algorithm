#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cmath>

using namespace std;

int arr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	int M, N;
	cin >> M >> N;

	for (int i = 2; i <= sqrt(N); i++)
	{
		if (arr[i] == 1) continue;
		else {
			for (int j = 2; j <= N; j++)
			{
				if (i * j > 10000) continue;
				arr[i*j] = 1;
			}
		}
	}

	int res = 0;
	int ans = 9999999;
	for (int i = M; i <= N; i++)
	{
		if (i == 1) continue;
		if (arr[i] == 0) {
			res += i;

			if (ans > i) {
				ans = i;
			}
		}
	}

	if (res == 0) {
		cout << -1;
		return 0;
	}

	cout << res << "\n" << ans;
	return 0;
}