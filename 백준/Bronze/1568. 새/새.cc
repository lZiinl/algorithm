#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	int N;
	cin >> N;

	int cnt = 1;
	int result = 0;

	while (1) {

		if (N < cnt) {
			cnt = 1;
			continue;
		}

		N -= cnt;
		cnt++;
		result++;

		if (N == 0) break;
	}

	cout << result;

	return 0;
}