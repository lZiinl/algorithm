#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

long long int A, B;

void input() {
	cin >> A >> B;
}

struct Node
{
	long long int num;
	int cnt;
};

void solve() {

	queue<Node>q;
	q.push({ A, 1 });

	while (!q.empty()) {

		Node now = q.front();
		q.pop();

		for (int i = 0; i < 2; i++){

			long long int ny = 0;

			if (i == 0) {
				ny = now.num * 2;
			}
			else {
				ny = now.num * 10 + 1;
			}

			if (ny > B) continue;
			if (ny == B) {
				cout << now.cnt + 1;
				return;
			}

			q.push({ ny, now.cnt + 1 });
		}
	}
	cout << -1;
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
