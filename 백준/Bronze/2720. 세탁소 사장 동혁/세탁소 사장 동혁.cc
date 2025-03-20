#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++){
		int S;
		cin >> S;

		cout << S / 25 << " ";
		S %= 25;

		cout << S / 10 << " ";
		S %= 10;

		cout << S / 5 << " ";
		S %= 5;

		cout << S  << "\n";

	}

	return 0;
}