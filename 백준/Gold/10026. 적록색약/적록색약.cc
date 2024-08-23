#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
char map[101][101];
int vis_no[101][101];
int vis_ad[101][101];

struct Node
{
	int x, y, num;
};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void input() {
	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> map[i];
	}
}

void bfs_no() {

	int cnt = 0;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){

			if (vis_no[i][j] != 0) continue;

			cnt++;
			queue<Node>q;
			q.push({ j, i, cnt});
			vis_no[i][j] = cnt;

			while (!q.empty()) {

				Node now = q.front();
				q.pop();

				for (int k = 0; k < 4; k++){

					int ny = now.y + dy[k];
					int nx = now.x + dx[k];

					if (vis_no[ny][nx] != 0) continue;
					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if (map[ny][nx] != map[now.y][now.x]) continue;

					q.push({ nx, ny, cnt });
					vis_no[ny][nx] = cnt;

				}
			}
		}
	}
	cout << cnt << " ";
}

void bfs_ad() {

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (vis_ad[i][j] != 0) continue;

			cnt++;
			queue<Node>q;
			q.push({ j, i, cnt });
			vis_ad[i][j] = cnt;

			while (!q.empty()) {

				Node now = q.front();
				q.pop();

				for (int k = 0; k < 4; k++) {

					int ny = now.y + dy[k];
					int nx = now.x + dx[k];

					if (vis_ad[ny][nx] != 0) continue;
					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					
					if (map[now.y][now.x] == 'B') {
						if (map[now.y][now.x] != map[ny][nx]) continue;
					}
					else {
						if (map[ny][nx] == 'B') continue;
					}

					q.push({ nx, ny, cnt });
					vis_ad[ny][nx] = cnt;

				}
			}
		}
	}
	cout << cnt << " ";
}

void solve() {
	
	bfs_no();
	bfs_ad();

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
