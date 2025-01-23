#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++){
		int arr[81] = {};

		string S;
		cin >> S;

		int M = S.length();

		int cnt = 0;

		for (int j = 0; j < M; j++){
			if (S[j] == 'O') cnt++;
			else { cnt = 0; }
			arr[j] = cnt;
		}

		int ans = 0;
		for (int j = 0; j < M; j++){
			ans += arr[j];
		}

		cout << ans << "\n";
	}

	return 0;
}