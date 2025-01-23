#define _CRT_SERCURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;

bool check(int num) {
	for (int i = 2; i < num/2; i++){
		if (num % i == 0) return false;
	}
	return true;
}

void dfs(int num, int level) {

	if (level == N) {

		if (check(num)) {
			cout << num << "\n";
		}
		return;
	}

	for (int i = 1; i < 10; i++){
		if (i % 2 == 0) continue;

		if (check(num * 10 + i)) {
			dfs(num * 10 + i, level +1);
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);

	return 0;
}