#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

using namespace std;

int N, M;
int map[200005];

void solve() {

	queue<int>q;
	q.push(N);
	map[N] = 1;

	while (1) {

		int now = q.front();
		q.pop();

		for (int i = 0; i < 3; i++){

			int ny = 0;

			if (i == 0) {
				ny = now + 1;
			}
			else if (i == 1) {
				ny = now - 1;
			}
			else {
				ny = now * 2;
			}

			if (ny < 0 || ny>200000) continue;
			if (map[ny] != 0) continue;

			map[ny] = map[now] + 1;
			if (ny == M) return;
			q.push(ny);

		}
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	cin >> N >> M;

	if (N == M) {
		cout << 0;
		return 0;
	}

	solve();

	cout << map[M] - 1;

	return 0;
}