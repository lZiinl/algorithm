#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int H, W, X, Y;
int arr[700][700];

void input() {
	cin >> H >> W >> X >> Y;

	for (int i = 0; i < H+X; i++){
		for (int j = 0; j < W+Y; j++){
			cin >> arr[i][j];
		}
	}
}

void solve() {
	for (int i = X; i < H+X; i++){
		for (int j = Y; j < W+Y; j++){
			arr[i][j] = arr[i][j] - arr[i - X][j - Y];
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	input();
	solve();

	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}