#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int N;
int result[21] = { 0,1, };

void input() {
	cin >> N;
}

void solve(int now) {
	if (now > N) {
		return;
	}

	result[now] = result[now - 1] + result[now - 2];
	solve(now + 1);
}

int main() {

	//freopen("sample.txt", "r", stdin);
	input();
	solve(2);

	cout << result[N];

	return 0;
}