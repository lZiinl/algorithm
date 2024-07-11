#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<cmath>
#include<unordered_map>
#include<cstring>

using namespace std;

struct Node {
	int y, x;
};

//연합국의 수와 총 인구수 저장
struct Uni {
	int num;
	int s_pop;
};

int N, L, R;
int map[101][101];
int vis[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
//연합수 확인
int v_cnt;

//연합국의 수와 총 인구수 저장
unordered_map<int, Uni> un;

void input() {
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
		}
	}
}

void init() {
	un.clear();
	v_cnt = 1;
	memset(vis, 0, sizeof(vis));
}

void bfs(int sp_y, int sp_x) {
	queue<Node> q;
	q.push({ sp_y, sp_x });
	vis[sp_y][sp_x] = v_cnt;
	un[v_cnt].num++;
	un[v_cnt].s_pop += map[sp_y][sp_x];

	while (!q.empty()){
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++){
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			//벽 체크
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			//연합이 있는지 확인
			if (vis[ny][nx] != 0) continue;

			int gap = abs(map[now.y][now.x] - map[ny][nx]);

			if ( gap >= L && gap <= R ){
				vis[ny][nx] = v_cnt;
				un[v_cnt].num++;
				un[v_cnt].s_pop += map[ny][nx];

				q.push({ ny,nx });
			}
		}
	}
	v_cnt++;
}

void find_sp() {

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){

			if (vis[i][j] == 0) {
				bfs(i, j);
			}
		}
	}
}

void imigrate() {
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){

			if (vis[i][j] != 0) {
				int uni_num = vis[i][j];
				map[i][j] = un[uni_num].s_pop / un[uni_num].num;
			}
		}
	}
}

int main() {

	//freopen("sample.txt", "r", stdin);

	input();
	int cnt = 0;

	while (1) {

		v_cnt = 1;
		init();
		find_sp();

		if (v_cnt == (N * N + 1)) {
			cout << cnt;
			break;
		}

		imigrate();
		cnt++;
	}

	return 0;
}