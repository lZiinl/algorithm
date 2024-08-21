#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

struct Node{
	int x, y;
};

int T;
int CV, sx, sy, ex, ey;
int beer;

Node C[101];
int vis[101];

void init() {

	for (int i = 0; i < 101; i++){
		vis[i] = 0;
	}

	for (int i = 0; i < 101; i++){
		C[i].x = 0;
		C[i].y = 0;
	}
}

void input() {
	cin >> CV;			//편의점 수
	cin >> sx >> sy;	//상근이 집

	for (int i = 0; i <= CV; i++){
		cin >> C[i].x >> C[i].y;

		if (i == CV) {
			ex = C[i].x;
			ey = C[i].y;
		}
	}
}

void solve() {
	
	queue<Node> q;
	q.push({ sx, sy });

	while (!q.empty()) {

		Node now = q.front();
		q.pop();

		if (now.x == ex && now.y == ey) {
			cout << "happy\n";
			return;
		}

		for (int i = 0; i <= CV; i++){

			if (vis[i] == 1) continue;

			int dist = abs(now.x - C[i].x) + abs(now.y - C[i].y);

			if (dist <= 1000) {
				q.push({ C[i].x , C[i].y });
				vis[i] = 1;
			}
		}
	}
	cout << "sad\n";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	cin >> T;

	for (int testcase = 0; testcase < T; testcase++){
		init();
		input();
		solve();
	}

	return 0;
}