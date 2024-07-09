#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

using namespace std;

int N, M;
char map[101][101];
struct Node {
	int y, x;
};

int dx[4] = { 1, 0, -1 ,0 };
int dy[4] = { 0, 1, 0, -1 };

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++){
		cin >> map[i];
	}
}

void solve() {
	int vis[101][101] = { 0, };

	queue<Node> q;
	q.push({ 0,0 });
	vis[0][0] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++){

			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (map[ny][nx] == '0') continue;
			if (vis[ny][nx] != 0) continue;

			vis[ny][nx] = vis[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}
	cout << vis[N - 1][M - 1];
}

int main() {

	//freopen("sample.txt", "r", stdin);
	input();
	solve();

	return 0;
}