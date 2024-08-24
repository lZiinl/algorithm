#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int arr[11];

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
}


void solve() {

	int sum = 0;

	for (int i = N-1; i >= 0; i--){

		int r1 = M / arr[i];
		sum += r1;

		M %= arr[i];
	}
	cout << sum;
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
