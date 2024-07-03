#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int N, M, sp;
int vis_dfs[1001];
int vis_bfs[1001];
int flag;

vector<int>edge[1001];

void input() {
	cin >> N >> M >> sp;

	for (int i = 0; i < M; i++){
		int from, to;
		cin >> from >> to;
		edge[from].push_back(to);
		edge[to].push_back(from);
	}

	for (int i = 0; i <= N; i++){
		sort(edge[i].begin(), edge[i].end());
	}
}

void dfs(int level, int node) {

	cout << node << " ";
	vis_dfs[node] = 1;

	if (level == N) {
		flag = 1;
		return;
	}

	for (int i = 0; i < edge[node].size(); i++){

		if (vis_dfs[edge[node][i]] == 1) continue;
		dfs(level + 1, edge[node][i]);
		if (flag == 1) return;
	}
}

void bfs() {

	queue<int>q;
	q.push(sp);
	vis_bfs[sp] = 1;

	while (!q.empty()) {

		int now = q.front();
		q.pop();
		
		cout << now << " ";

		for (int i = 0; i < edge[now].size(); i++){
			if (vis_bfs[edge[now][i]] == 1) continue;
			vis_bfs[edge[now][i]] = 1;
			q.push(edge[now][i]);
		}
	}
}

void solve() {

	dfs(1, sp);
	cout << "\n";
	bfs();
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	input();

	if (N == 1) {
		cout << sp << "\n" << sp;
		return 0;
	}

	solve();

	return 0;
}