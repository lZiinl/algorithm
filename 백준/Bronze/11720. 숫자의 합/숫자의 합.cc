#define _CRT_SECURE_MO_WARNINGS
#include <iostream>

using namespace std;

char c[101];

void input() {
	
}

void solve() {
	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	//input();
	int i;
	cin >> i >> c;
	int sum = 0;

	for (int j = 0; j < i; j++){
		sum += int(c[j]);
		sum -= 48;
	}
	cout << sum;
	//solve();

	return 0;
}
