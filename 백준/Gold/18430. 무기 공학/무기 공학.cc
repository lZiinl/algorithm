#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, M;
int map[6][6];
int n_max;
int vis[6][6];

int da[4][4] = {
	1,0,0,1,
	0,1,-1,0,
	-1,0,0,-1,
	0,-1,1,0
};

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
		}
	}
}

void dfs(int px, int py, int s) {

	for (int i = 0; i < 4; i++){

		int nx1 = px + da[i][0];
		int ny1 = py + da[i][1];
		int nx2 = px + da[i][2];
		int ny2 = py + da[i][3];

		if (nx1 < 0 || ny1 < 0 || nx2 < 0 || ny2 < 0) continue;
		if (nx1 >= M || ny1 >= N || nx2 >= M || ny2 >= N) continue;
		if (vis[ny1][nx1] == 1 || vis[ny2][nx2] == 1) continue;

		int sum = s + (map[py][px] * 2) + map[ny1][nx1] + map[ny2][nx2];
		
		if (sum > n_max) {
			n_max = sum;
		}

		vis[ny1][nx1] = 1;
		vis[ny2][nx2] = 1;

		for (int j = py; j < N; j++){
			for (int k = 0; k < M; k++){
				if (vis[j][k] == 1) continue;

				vis[j][k] = 1;
				dfs(k, j, sum);
				vis[j][k] = 0;

			}
		}

		vis[ny1][nx1] = 0;
		vis[ny2][nx2] = 0;

	}
}

void solve() {
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			vis[i][j] = 1;
			dfs(j, i, 0);
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
	solve();

	cout << n_max;

	return 0;
}