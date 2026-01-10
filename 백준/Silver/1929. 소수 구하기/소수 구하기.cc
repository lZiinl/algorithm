#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int arr[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	int M, N;
	cin >> M >> N;
	arr[1] = 1;
	for (int i = 2; i*i <= N; i++)
	{
		if (arr[i] == 1) continue;
		for (int j = i * i; j <= N; j += i)
		{
			arr[j] = 1;
		}
	}

	for (int i = M; i <= N; i++)
	{
		if (arr[i] == 0) {
			cout << i << "\n";
		}
	}
	return 0;
}