#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;

struct Node {
	int y, x;
};

vector<Node> house;
vector<Node> chicken;
vector<int> check;

int nmin = 21e8;

void input() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int val;
			cin >> val;

			if (val == 1) {
				house.push_back({ i, j });
			}
			else if (val == 2) {
				chicken.push_back({ i, j });
			}
		}
	}
}

void dfs(int n, int level) {

	if (level == M) {
		int sum = 0;

		for (int i = 0; i < house.size(); i++) {
			int dist = 21e8;
			int r = 0;

			for (int j = 0; j < check.size(); j++) {
				r = abs(house[i].x - chicken[check[j]].x) + abs(house[i].y - chicken[check[j]].y);
				if (dist > r) dist = r;
			}
			sum += dist;
		}
		if (nmin > sum) nmin = sum;

		return;
	}

	for (int i = n; i < chicken.size(); i++) {

		if (chicken.size() - i < M - check.size()) return;

		check.push_back(i);
		dfs(i + 1, level + 1);
		check.pop_back();
	}
}

void solve() {

	dfs(0, 0);

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	input();
	solve();

	cout << nmin;

	return 0;
}
