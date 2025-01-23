#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <queue>

using namespace std;

int map[9][9];
int N, M;
int ans;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct Node {
	int y, x;
};

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
		}
	}
}

int temp[9][9];

void cp() {
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			temp[i][j] = map[i][j];
		}
	}
}

void bfs() {

	int vis[9][9] = {};

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (vis[i][j] == 1) continue;

			if (map[i][j] == 2) {
				queue<Node> q;

				q.push({ i,j });
				vis[i][j] = 1;

				while (!q.empty()) {

					Node now = q.front();
					q.pop();

					for (int k = 0; k < 4; k++){

						int nx = now.x + dx[k];
						int ny = now.y + dy[k];

						if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
						if (vis[ny][nx] == 1) continue;
						if (temp[ny][nx] == 1 || temp[ny][nx] == 3) continue;

						vis[ny][nx] = 1;
						temp[ny][nx] = 2;
						q.push({ ny,nx });

					}
				}
			}
		}
	}
}

void check() {
	int result = 0;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (temp[i][j] == 0) result++;
		}
	}

	if (ans < result) ans = result;
}

void dfs(int level, int y, int x) {

	if (level == 3) {

		cp();
		bfs();
		check();

		return;
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){

			if (map[i][j] != 0) continue;
			
			map[i][j] = 3;
			dfs(level + 1, i, j);
			map[i][j] = 0;
		}
	}
}

void solve() {

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){

			if (map[i][j] != 0) continue;

			map[i][j] = 3;
			dfs(1, i, j);
			map[i][j] = 0;
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
	cout << ans;

	return 0;
}