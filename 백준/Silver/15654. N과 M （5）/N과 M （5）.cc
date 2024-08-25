#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int>v;
int arr[8];
int vis[8];

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++){
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
}

void dfs(int level, int now) {

	if (level == M) {
		for (int i = 0; i < M; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < v.size(); i++){

		if (vis[i] == 1) continue;

		arr[level] = v[i];
		vis[i] = 1;
		dfs(level + 1, i);
		vis[i] = 0;
	}
}

void solve() {

	for (int i = 0; i < v.size(); i++){
		arr[0] = v[i];
		vis[i] = 1;
		dfs(1, i);
		vis[i] = 0;
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
