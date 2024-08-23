#define _CRT_SECURE_MO_WARNINGS
#include <iostream>

using namespace std;

int num[9];
int result;
int ind;

void input() {
	for (int i = 0; i < 9; i++){
		cin >> num[i];

		if (num[i] > result) {
			result = num[i];
			ind = i;
		}
	}
	cout << result << "\n" << ind + 1;
}

void solve() {
	
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
