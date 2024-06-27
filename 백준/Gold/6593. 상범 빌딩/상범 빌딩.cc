#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int L, R, C;
char map[31][31][31];
int vis[31][31][31];
int dy[6] = { 1, -1, 0, 0, 0, 0 };
int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int sp_x, sp_y, sp_z;
int ep_x, ep_y, ep_z;

struct Node {
	int x, y, z;
};

void init() {

	for (int i = 0; i < L; i++){
		for (int j = 0; j < R; j++){
			for (int k = 0; k < C; k++){
				map[i][j][k] = ' ';
				vis[i][j][k] = 0;
			}
		}
	}
}

void input() {
	cin >> L >> R >> C;


	for (int i = 0; i < L; i++){
		for (int j = 0; j < R; j++){
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < L; i++){
		for (int j = 0; j < R; j++){
			for (int k = 0; k < C; k++){
				if (map[i][j][k] == 'S') {
					sp_x = k;
					sp_y = j;
					sp_z = i;
				}
				else if (map[i][j][k] == 'E') {
					ep_x = k;
					ep_y = j;
					ep_z = i;
				}
			}
		}
	}
}

void solve() {

	queue<Node> q;
	q.push({ sp_x, sp_y, sp_z });

	while (!q.empty()) {

		Node now = q.front();
		q.pop();

		if (now.x == ep_x && now.y == ep_y && now.z == ep_z) break;

		for (int i = 0; i < 6; i++){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			int nz = now.z + dz[i];

			if (nx < 0 || ny < 0 || nz < 0 || nx >= C || ny >= R || nz >= L) continue;
			if (map[nz][ny][nx] == '#') continue;
			if (vis[nz][ny][nx] != 0) continue;

			q.push({ nx,ny,nz });
			vis[nz][ny][nx] = vis[now.z][now.y][now.x] + 1;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	while (1) {

		init();
		input();
		if (L == 0 && R == 0 && C == 0) break;

		solve();

		if (vis[ep_z][ep_y][ep_x] != 0) {
			cout << "Escaped in " << vis[ep_z][ep_y][ep_x] << " minute(s).\n";
		}
		else {
			cout << "Trapped!\n";
		}
	}
	

	return 0;
}