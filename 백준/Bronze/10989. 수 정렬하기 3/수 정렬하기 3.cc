#define _CRT_SERCURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int num[10001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++){
		int temp;
		cin >> temp;
		num[temp]++;
	}

	for (int i = 0; i < 10001; i++){
		if (num[i] < 1) continue;

		while (num[i] > 0) {
			cout << i << "\n";
			num[i]--;
		}
	}

	return 0;
}