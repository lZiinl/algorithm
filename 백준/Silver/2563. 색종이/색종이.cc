#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

bool status[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	int N;
	cin >> N;

	int y, x;

	int result = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> y >> x;

		for (int i = y; i < y+10; i++)
		{
			for (int j = x; j < x+10; j++)
			{
				status[i][j] = 1;
			}
		}
	}
	
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			if (status[i][j] == 1) {
				result++;
			}
		}
	}

	cout << result;

	return 0;
}