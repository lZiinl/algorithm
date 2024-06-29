#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M, P;

vector<int> num;

void input() {
	cin >> N >> M >> P;

	for (int i = 0; i < N; i++){
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}

	sort(num.begin(), num.end(), greater<>());
}

void solve() {

	if (N == 0) {
		cout << 1;
		return;
	}

	if (N == P) {

		if (M == num[P - 1]) {
			cout << -1;
			return;
		}

		for (int i = 0; i < P; i++){
			if (M > num[i]) {
				cout << i + 1;
				return;
			}
			else if (M == num[i]) {
				if (i + 1 == P) break;
				cout << i + 1;
				return;
			}
		}
	}
	else {
		for (int i = 0; i < P; i++) {
			if (M > num[i]) {
				cout << i + 1;
				return;
			}
			else if (M == num[i]) {
				cout << i + 1;
				return;
			}
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