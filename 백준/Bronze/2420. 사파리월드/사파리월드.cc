#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);
	long long N, M;

	cin >> N >> M;

	long long ans = abs(N - M);
	cout << ans;

	return 0;
}