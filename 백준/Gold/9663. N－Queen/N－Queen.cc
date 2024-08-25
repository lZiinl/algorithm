#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int map[16];
int cnt;

void input() {
	cin >> N;
}

int check(int a, int b) {
	for (int i = 0; i < a; i++) {
		if ((i + map[i]) == (a + b) || (i - map[i]) == (a - b) || map[i] == map[a]) {
			return 1;
		}
	}
	return 0;
}

void solve(int level) {

	if (level == N) {
		cnt++;
		return;
	}

	for (int y = 0; y < N; y++) {
		int check1 = 0;
		map[level] = y;

		if (level > 0) {
			check1 = check(level, y);
		}

		if (check1 == 0) {
			solve(level + 1);
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	input();
	solve(0);

	cout << cnt;

	return 0;
}
