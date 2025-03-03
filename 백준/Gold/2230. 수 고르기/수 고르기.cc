#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M;
vector<int>v;

void input() {
	cin >> N >> M;

	v.resize(N);

	for (int i = 0; i < N; i++){
		cin >> v[i];
	}

	sort(v.begin(), v.end());
}

void solve() {

	int sp = 0;
	int ep = 0;
	int ans = 21e8;

	while (ep < N) {

		if (v[ep] - v[sp] < M) {
			ep++;
			continue;
		}

		else if (v[ep] - v[sp] == M) {
			cout << M;
			return;
		}

		else {
			if (v[ep] - v[sp] < ans) {
				ans = v[ep] - v[sp];
			}
			sp++;
		}
	}
	cout << ans;
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
