#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long num[2001];
int cnt;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);
}

void solve() {
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (i == j) continue;
			int flag = 0;
			long long temp = num[i] - num[j];

			int sp = 0;
			int ep = N;

			while (sp < ep) {
				int mid = (sp + ep) / 2;

				if (temp - num[mid] > 0) {
					sp = mid + 1;
				}
				else if (temp - num[mid] < 0) {
					ep = mid;
				}
				else {
					if (j == mid || i == mid) {
						sp = mid + 1;
					}
					else {
						cnt++;
						flag = 1;
						break;
					}
				}
			}

			if (flag == 1) {
				break;
			}
		}
	}
}

int main() {

	//freopen("sample.txt", "r", stdin);

	input();
	if (N > 2) {
		solve();
	}
	cout << cnt;

	return 0;
}