#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int min(int a, int b) {
	if (a < b) return a;
	
	return b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	int x, y, w, h;

	cin >> x >> y >> w >> h;

	int res1, res2;

	res1 = min(x-0, w-x);
	res2 = min(y - 0, h - y);

	int ans;
	ans = min(res1, res2);

	cout << ans;

	return 0;
}