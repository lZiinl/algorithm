#define _CRT_SERCURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int flag;

vector<int> v[2001];
int vis[2001];

void input() {
	cin >> N >> M;

	for (int i = 0; i < M; i++){
		int t1, t2;
		cin >> t1 >> t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
}

void solve(int level, int num) {

	if (level == 5) {
		cout << 1;
		flag = 1;
		return;
	}

	for (int i = 0; i < v[num].size(); i++){

		if (vis[v[num][i]] == 1) continue;

		vis[v[num][i]] = 1;
		solve(level + 1, v[num][i]);
		vis[v[num][i]] = 0;

		if (flag == 1) return;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	for (int i = 0; i < M; i++){
		
		if (flag == 1) return 0;

		vis[i] = 1;
		solve(1 , i);
		vis[i] = 0;
	}

	cout << 0;

	return 0;
}