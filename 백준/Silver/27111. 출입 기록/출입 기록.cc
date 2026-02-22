#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

bool status[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	int N;
	cin >> N;

	int a, b;

	int result = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;

		if (b == 0) {
			if (status[a] == 0) {
				result++;
			}
			status[a] = b;
		}
		else {
			if (status[a] == 1) {
				result++;
			}
			status[a] = b;
		}
	}

	for (int i = 1; i <= 200000; i++)
	{
		if (status[i] == 1) {
			result++;
		}
	}

	cout << result;

	return 0;
}