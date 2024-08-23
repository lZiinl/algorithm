#define _CRT_SECURE_MO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int N;

void input() {
	cin >> N;
}

void print1() {
	cout << "@@@@@";
}

void print2() {
	cout << "@";
}

void solve() {

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			print1();
		}
		cout << "\n";
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			print2();
		}
		cout << "\n";
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			print1();
		}
		cout << "\n";
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			print2();
		}
		cout << "\n";
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			print1();
		}
		cout << "\n";
	}
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
