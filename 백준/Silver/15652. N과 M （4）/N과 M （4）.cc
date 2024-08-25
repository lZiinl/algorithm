#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N, M;
int arr[8];

void input() {
	cin >> N >> M;
}

void dfs(int level, int now) {

	if (level == M) {
		for (int i = 0; i < M; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = now; i <= N; i++){
		arr[level] = i;
		dfs(level + 1, i);
	}
}

void solve() {

	for (int i = 1; i <= N; i++){
		arr[0] = i;
		dfs(1, i);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	input();
	solve();

	return 0;
}
