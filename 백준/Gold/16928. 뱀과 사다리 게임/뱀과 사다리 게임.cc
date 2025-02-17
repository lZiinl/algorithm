#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int map[101];

struct Node{
	int from, to;
};

vector<Node> ladder;
vector<Node> snake;

void input() {

	cin >> N >> M;
	ladder.resize(N);
	snake.resize(M);

	for (int i = 0; i < N; i++){
		cin >> ladder[i].from >> ladder[i].to;
	}

	for (int i = 0; i < M; i++){
		cin >> snake[i].from >> snake[i].to;
	}
}

void solve() {
	
	queue<int> q;
	q.push(1);

	while (!q.empty()) {

		int now = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++){

			int ny = now + i;
			if (map[ny] != 0) continue;

			map[ny] = map[now] + 1;

			for (int j = 0; j < N; j++){

				if (ladder[j].from == ny) {

					if (map[ladder[j].to] == 0) {
						map[ladder[j].to] = map[ny];
					}

					ny = ladder[j].to;
					break;
				}
			}

			for (int j = 0; j < M; j++) {

				if (snake[j].from == ny) {

					if (map[snake[j].to] == 0) {
						map[snake[j].to] = map[ny];
					}

					ny = snake[j].to;
					break;
				}
			}
			q.push(ny);

			if (ny == 100) return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("sample.txt", "r", stdin);

	input();
	solve();

	cout << map[100];

	return 0;
}