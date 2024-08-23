#define _CRT_SECURE_MO_WARNINGS
#include <iostream>

using namespace std;

int arr[5];

void input() {
	for (int i = 0; i < 5; i++){
		cin >> arr[i];
	}
}

void solve() {
	int num = 0;

	for (int i = 0; i < 5; i++){
		num += arr[i] * arr[i];
	}

	num %= 10;
	cout << num;
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
