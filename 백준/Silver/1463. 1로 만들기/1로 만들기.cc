#define _CRT_SECURE_MO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int N;
int vis[1000001];

struct Node
{
	int num, ind;
};

void input() {
	cin >> N;
}

void solve() {

	queue<Node>q;
	q.push({ 1,0 });

	while (!q.empty()) {

		Node now = q.front();
		q.pop();

		for (int i = 0; i < 3; i++){

			int ny = 0;

			if (i == 0) {
				ny = now.num * 3;
			}
			else if (i == 1) {
				ny = now.num * 2;
			}
			else {
				ny = now.num + 1;
			}

			if (ny > 1000001) continue;
			if (vis[ny] != 0) continue;

			if (ny == N) {
				cout << now.ind + 1;
				return;
			}

			vis[ny] = now.ind + 1;
			q.push({ ny, now.ind + 1 });
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	input();

	if (N == 1) {
		cout << 0;
		return 0;
	}

	solve();

	return 0;
}
