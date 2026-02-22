#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	int N;
	cin >> N;

	int a, b;
	for (int i = 0; i < N; i++)
	{
		int result = 1;
		cin >> a >> b;

		for (int i = 0; i < b; i++)
		{
			result *= a;
			result %= 10;
		}

		if (result == 0) result = 10;
		cout << result << "\n";
	}

	return 0;
}