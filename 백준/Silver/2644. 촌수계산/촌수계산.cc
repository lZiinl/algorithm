#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n;
int S, E;
int N;

vector<int>v[101];
int vis[101];

void input() {
	cin >> n;

	cin >> S >> E;

	cin >> N;

	for (int i = 0; i < N; i++){
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
}


void solve() {
	
	queue<int>q;
	q.push(S);
	vis[S] = 0;

	while (!q.empty()) {

		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++){

			int ny = v[now][i];

			if (vis[ny] != -1) continue;

			q.push(ny);
			vis[ny] = vis[now] + 1;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	input();

	for (int i = 0; i <= n; i++){
		vis[i] = -1;
	}

	solve();

	cout << vis[E];

	return 0;
}