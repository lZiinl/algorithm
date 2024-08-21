#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N;
int map[1001][1001];
int vis[1001][1001];
int lmax;
int nmax;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct Node
{
	int x, y;
};

void input() {
	cin >> N;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
			
			if (map[i][j] > nmax) {
				nmax = map[i][j];
			}
		}
	}
}

void solve(int level) {
	
	queue<Node> q;
	int cnt = 1;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){

			if (vis[i][j] != 0) continue;

			if (map[i][j] <= level) continue;

			q.push({ j, i });
			vis[i][j] = cnt;

			while (!q.empty()) {

				Node now = q.front();
				q.pop();

				for (int k = 0; k < 4; k++){

					int ny = now.y + dy[k];
					int nx = now.x + dx[k];

					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if (vis[ny][nx] != 0) continue;
					if (map[ny][nx] <= level) continue;

					q.push({ nx, ny });
					vis[ny][nx] = cnt;
				}
			}

			if (cnt > lmax) {
				lmax = cnt;
			}

			cnt++;
		}
	}
}

void init() {
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			vis[i][j] = 0;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	input();

	for (int i = 0; i <= 100; i++){

		if (i >= nmax) {
			break;
		}

		init();
		solve(i);
	}

	cout << lmax;

	return 0;
}