#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	int a, b;

	cin >> a >> b;

	if (a > 0 && b > 0) cout << 1;
	else if (a < 0 && b>0) cout << 2;
	else if (a < 0 && b < 0) cout << 3;
	else cout << 4;

	return 0;
}