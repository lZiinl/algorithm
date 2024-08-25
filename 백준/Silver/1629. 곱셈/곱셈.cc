#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;

long long int A, B, C;

void input() {
	cin >> A >> B >> C;
}

void solve() {
	long long int r = 1;

	while (B > 0) {
		if (B % 2) {
			r *= A;
			r %= C;
		}

		A *= A;
		A %= C;

		B /= 2;
	}

	cout << r;
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
