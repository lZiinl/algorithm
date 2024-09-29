#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int map[101][101];
vector<int>check;

struct Node{
	int y, x;
};

void input() {

	cin >> M >> N >> K;

	for (int i = 0; i < K; i++){

		int x1, x2, y1, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		for (int y = y1; y < y2; y++){
			for (int x = x1; x < x2; x++){
				map[y][x] = 1;
			}
		}
	}
}

void solve() {

	int cnt = 1;

	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			if (map[i][j] != 0) continue;

			queue<Node> q;
			q.push({ i,j });
			cnt++;
			map[i][j] = cnt;
			int mcnt = 0;

			while (!q.empty()) {

				Node now = q.front();
				q.pop();
				mcnt++;

				for (int k = 0; k < 4; k++){
					int ny = now.y + dy[k];
					int nx = now.x + dx[k];

					if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
					if (map[ny][nx] != 0) continue;

					q.push({ ny,nx });
					map[ny][nx] = cnt;

				}
			}
			check.push_back(mcnt);
		}
	}

	cout << cnt - 1 << "\n";

	sort(check.begin(), check.end());

	for (int i = 0; i < check.size(); i++){
		cout << check[i] << " ";
	}

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