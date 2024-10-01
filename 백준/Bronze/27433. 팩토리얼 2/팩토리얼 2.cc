#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int N;
long long int result=1;

void input() {
	cin >> N;
}

void solve(int now) {
	if (now == 0) {
		return;
	}

	result = result * now;
	solve(now - 1);
}

int main() {

	//freopen("sample.txt", "r", stdin);
	input();
	solve(N);

	cout << result;

	return 0;
}