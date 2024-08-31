#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

//백준 23278번 코드
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	cout.precision(10);

	int n, l, h;
	cin >> n >> l >> h;
	double arr[51];
	double sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr, arr + n);
	for (int i = 0; i < l; i++) {
		sum -= arr[i];
	}
	for (int i = 0; i < h; i++) {
		sum -= arr[n - i - 1];
	}
	cout << (double)(sum / (n - l - h)) << endl;
}