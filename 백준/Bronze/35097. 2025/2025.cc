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
	int num;

	while (1) {
		cin >> num;
		if (num == 0) return 0;

		int sum = 0;

		for (int i = 1; i <= num; i++)
		{
			for (int j = 1; j <= num; j++)
			{
				sum += i * j;
			}
		}
		cout << sum << "\n";
	}
}