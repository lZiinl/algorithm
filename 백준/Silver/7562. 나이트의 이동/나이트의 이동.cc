#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int T;
int N;
int kx, ky;
int tx, ty;
int map[301][301];

struct Node {
	int x, y;
};

int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; tc++){
		cin >> N;
		cin >> kx >> ky;
		cin >> tx >> ty;
		memset(map, -1, sizeof(map));

		queue<Node>q;
		q.push({ kx,ky });
		map[kx][ky] = 0;

		while (!q.empty()) {
			Node now = q.front();
			q.pop();

			for (int i = 0; i < 8; i++){
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];

				if (nx >= N || ny >= N || nx < 0 || ny < 0) continue;
				if (map[nx][ny] != -1) continue;

				map[nx][ny] = map[now.x][now.y] + 1;
				q.push({ nx,ny });
			}
		}
		cout << map[tx][ty] << endl;
	}

	return 0;
}