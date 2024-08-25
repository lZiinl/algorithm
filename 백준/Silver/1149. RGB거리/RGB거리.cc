#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int N;

int house[1001][3];
int cost[3];

void input() {

}

void solve() {
	cin >> N;

	house[0][0] = 0;
	house[0][1] = 0;
	house[0][2] = 0;

	for (int i = 1; i <= N; i++){
		cin >> cost[0] >> cost[1] >> cost[2];

		house[i][0] = min(house[i - 1][1], house[i - 1][2]) + cost[0];
		house[i][1] = min(house[i - 1][0], house[i - 1][2]) + cost[1];
		house[i][2] = min(house[i - 1][1], house[i - 1][0]) + cost[2];
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	//input();
	solve();

	cout << min(house[N][0], min(house[N][1], house[N][2]));

	return 0;
}
