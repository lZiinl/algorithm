#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	int N = 1000;
	arr[1] = 1;
	for (int i = 2; i*i <= N; i++)
	{
		if (arr[i] == 1) continue;
		for (int j = i * i; j <= N; j += i)
		{
			arr[j] = 1;
		}
	}

	int M;
	int ans = 0;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;

		if (arr[num] == 0) {
			ans++;
		}
	}

	cout << ans;

	return 0;
}