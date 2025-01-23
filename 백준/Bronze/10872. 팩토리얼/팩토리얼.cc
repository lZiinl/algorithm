#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);
	int N;

	cin >> N;

	long long ans = 1;

	for (int i = N; i > 0; i--){
		ans *= i;
	}

	cout << ans;

	return 0;
}