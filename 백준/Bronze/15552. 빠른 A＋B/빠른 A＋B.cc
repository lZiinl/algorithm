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

	for (int i = 0; i < N; i++){

		int t1, t2;
		cin >> t1 >> t2;
		cout << t1 + t2 << "\n";
	}

	return 0;
}