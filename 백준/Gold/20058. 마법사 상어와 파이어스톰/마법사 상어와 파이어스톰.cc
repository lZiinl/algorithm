#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int N, Q, L;
int map[80][80];
int cmd[1001];

int T;	// 전체 합
int sz; // 전체 map 크기

int min_map[80][80]; //회전시킬 map
int r_map[80][80];	 //회전된 map
int vis_map[80][80]; //bfs 방문 확인 map
int del_map[80][80]; //bfs 방문 확인 map
int len; //min_map 길이

int result;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct Node {
	int y, x;
};

void input() {
	cin >> N >> Q;
	sz = pow(2, N);

	for (int i = 0; i < sz; i++){
		for (int j = 0; j < sz; j++){
			cin >> map[i][j];
			T += map[i][j];
		}
	}

	for (int i = 0; i < Q; i++){
		cin >> cmd[i];
	}
}

void map_rotate() {

	for (int i = 0; i < len; i++){
		for (int j = 0; j < len; j++){
			r_map[j][len - 1 - i] = min_map[i][j];
		}
	}
}

void find_map(int y, int x) {

	for (int i = 0; i < len; i++){
		for (int j = 0; j < len; j++){
			min_map[i][j] = map[y + i][x + j];
		}
	}

	map_rotate();

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			map[y + i][x + j] = r_map[i][j];
		}
	}
}

void bfs() {

	for (int i = 0; i < sz; i++){
		for (int j = 0; j < sz; j++){

			if (map[i][j] == 0) continue;

			int i_cnt = 0;
			int nx = 0;
			int ny = 0;

			for (int k = 0; k < 4; k++){

				nx = j + dx[k];
				ny = i + dy[k];

				if (ny < 0 || nx < 0 || ny >= sz || nx >= sz) continue;
				if (map[ny][nx] == 0) continue;

				i_cnt++;
			}

			if (i_cnt < 3) del_map[i][j] = 1;
		}
	}
}

void delete_map() {

	for (int i = 0; i < sz; i++){
		for (int j = 0; j < sz; j++){
			map[i][j] -= del_map[i][j];
			T -= del_map[i][j];
			del_map[i][j] = 0;
		}
	}
}

void init() {
	for (int j = 0; j < sz; j++) {
		for (int k = 0; k < sz; k++) {
			vis_map[j][k] = 0;
		}
	}
}

void solve() {
	
	for (int i = 0; i < Q; i++){
		len = pow(2, cmd[i]);

		for (int j = 0; j < sz; j += len){
			for (int k = 0; k < sz; k += len){
				
				find_map(j, k);
			}
		}

		bfs();
		delete_map();
		//init();
	}
}

void bfs2() {

	for (int i = 0; i < sz; i++){
		for (int j = 0; j < sz; j++){

			if (vis_map[i][j] != 0) continue;
			if (map[i][j] == 0) continue;

			int cnt = 0;
			queue<Node>q;
			q.push({ i, j });
			vis_map[i][j] = 1;

			while (!q.empty()) {

				Node now = q.front();
				q.pop();
				cnt++;

				for (int k = 0; k < 4; k++) {

					int ny = now.y + dy[k];
					int nx = now.x + dx[k];

					if (ny < 0 || nx < 0 || ny >= sz || nx >= sz) continue;
					if (map[ny][nx] == 0) continue;
					if (vis_map[ny][nx] != 0) continue;

					q.push({ ny, nx });
					vis_map[ny][nx] = 1;
				}
			}

			if (result < cnt) result = cnt;
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
	bfs2();

	cout << T << "\n" << result;

	return 0;
}