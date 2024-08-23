#define _CRT_SECURE_MO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int T;
int arr[42] = { 0, 1, 1, 2, };


void input() {
	cin >> T;

	for (int i = 2; i < 42; i++){
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	for (int i = 0; i < T; i++){

		int temp;
		cin >> temp;

		if (temp == 0) {
			cout << 1 << " " << 0 << "\n";
		}
		else {
			cout << arr[temp - 1] << " " << arr[temp] << "\n";
		}
	}
}

void solve() {
	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	input();
	//solve();

	return 0;
}
