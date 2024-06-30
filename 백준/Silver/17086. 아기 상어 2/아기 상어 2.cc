#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M;
int map[51][51];
int vis[51][51];
int n_max;

int dy[8] = { 1, 0, -1, 0 , -1 , -1, 1, 1 };
int dx[8] = { 0, 1, 0, -1 , -1, 1, -1, 1 };

struct Node {
	int y, x;
};

queue<Node>q;

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push({ j,i });
				vis[i][j] = 1;
			}
		}
	}
}

void solve() {

	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		
		if (n_max < vis[now.x][now.y]) {
			n_max = vis[now.x][now.y];
		}

		for (int i = 0; i < 8; i++){
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (nx < 0 || ny < 0 || ny >= M || nx >= N) continue;
			if (vis[nx][ny] != 0) continue;

			q.push({ ny,nx });
			vis[nx][ny] = vis[now.x][now.y] + 1;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	input();
	solve();

	cout << n_max - 1;

	return 0;
}