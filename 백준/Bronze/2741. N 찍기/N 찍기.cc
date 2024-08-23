#define _CRT_SECURE_MO_WARNINGS
#include <iostream>

using namespace std;

int N;

void input() {
	cin >> N;
}

void solve() {
	for (int i = 1; i <= N; i++){
		cout << i << "\n";
	}
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
