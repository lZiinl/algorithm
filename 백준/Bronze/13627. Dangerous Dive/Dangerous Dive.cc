#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int N, R;
int vol[10001];

void input() {
	cin >> N >> R;

	if (N == R) {
		cout << "*";
		return;
	}

	int num = 0;
	for (int i = 0; i < R; i++){
		cin >> num;
		vol[num] = 1;
	}

	for (int i = 1; i <= N; i++){
		if (vol[i] == 0) {
			cout << i << " ";
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	input();

	return 0;
}