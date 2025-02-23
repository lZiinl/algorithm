#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M;

int map[51][51];
int map_vis[51][51];

struct Node {
	int y, x;
};

vector<Node>v;
vector<int> num;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int ans = -1;

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			cin >> map[i][j];
			map_vis[i][j] = -1;

			if (map[i][j] == 2) {
				v.push_back({ i,j });
			}
		}
	}
}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map_vis[i][j] = -1;
		}
	}
}

void bfs() {

	queue<Node>q;

	for (int i = 0; i < num.size(); i++) {
		int n = num[i];
		q.push({ v[n].y, v[n].x });
		map_vis[v[n].y][v[n].x] = 0;
	}

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {

			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (map[ny][nx] == 1) continue;
			if (map_vis[ny][nx] != -1) continue;

			q.push({ ny, nx });
			map_vis[ny][nx] = map_vis[now.y][now.x] + 1;

		}
	}
}

void check() {

	int t_max = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (map_vis[i][j] == -1 && map[i][j] != 1) return;

			if (map_vis[i][j] > t_max) {
				t_max = map_vis[i][j];
			}
		}
	}

	if (ans == -1) {
		ans = t_max;
	}
	else {
		if (ans > t_max) {
			ans = t_max;
		}
	}
}

void dfs(int n, int level) {

	if (level == M) {
		init();
		bfs();
		check();
		return;
	}

	for (int i = n + 1; i < v.size(); i++) {
		num.push_back(i);
		dfs(i, level + 1);
		num.pop_back();
	}
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	input();

	for (int i = 0; i <= v.size() - M; i++) {
		num.push_back(i);
		dfs(i, 1);
		num.pop_back();
	}

	cout << ans;

	return 0;
}
