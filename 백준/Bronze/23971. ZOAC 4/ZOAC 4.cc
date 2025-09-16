#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

// 0 CY 1 SK 2 

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);
	int H, W, N, M;
	cin >> H >> W >> N >> M;

	int t1 = H / (N + 1);
	if (H % (N + 1) != 0) t1++;

	int t2 = W / (M + 1);
	if (W % (M + 1) != 0) t2++;

	cout << t1 * t2;

	return 0;
}