#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N;
int arr[2][100001];
int dp[2][100001];

void input() {
	cin >> N;

	for (int i = 0; i < 2; i++){
		for (int j = 0; j < N; j++){
			cin >> arr[i][j];
		}
	}
}

void solve() {
	
	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];
	dp[0][1] = arr[0][1] + dp[1][0];
	dp[1][1] = arr[1][1] + dp[0][0];

	for (int i = 2; i < N; i++){
		dp[0][i] = arr[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
		dp[1][i] = arr[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
	}

	if (dp[0][N - 1] > dp[1][N - 1]) {
		cout << dp[0][N - 1] << "\n";
	}
	else {
		cout << dp[1][N - 1] << "\n";
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	int T;
	cin >> T;

	for (int testcase = 0; testcase < T; testcase++){
		input();
		solve();
	}

	return 0;
}