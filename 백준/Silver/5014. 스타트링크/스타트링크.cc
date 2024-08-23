#define _CRT_SECURE_MO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
int vis[1000001];

void input() {
	cin >> F >> S >> G >> U >> D;
}

struct Node
{
	int f, ind;
};

void solve() {

	queue<Node>q;
	q.push({ S, 0 });
	vis[S] = 1;

	while (!q.empty()) {

		Node now = q.front();
		q.pop();

		for (int i = 0; i < 2; i++){

			int ny;

			if (i == 0) {
				ny = now.f + U;
			}
			else {
				ny = now.f - D;
			}

			if (ny <= 0 || ny > F) continue;
			if (vis[ny] == 1) continue;

			if (ny == G) {
				cout << now.ind + 1;
				return;
			}

			vis[ny] = 1;
			q.push({ ny, now.ind + 1 });
		}
	}
	cout << "use the stairs";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	input();

	if (S == G) {
		cout << 0;
		return 0;
	}

	solve();

	return 0;
}
