#define _CRT_SECURE_MO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int arr[12] = { 1, 1, 2, 4, };
int T;

void input() {
	cin >> T;
	int n;

	for (int testcase = 0; testcase < T; testcase++){
		cin >> n;
		cout << arr[n] << "\n";
	}
}

void solve() {

	for (int i = 3; i < 12; i++){
		arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	solve();
	input();

	return 0;
}
