#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("sample.txt", "r", stdin);

	int N;
	double sum = 0;
	double n_max = 0;

	cin >> N;

	double arr[1001];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];

		if (n_max < arr[i]) {
			n_max = arr[i];
		}
	}

	for (int i = 0; i < N; i++) {
		sum = sum + (arr[i] / n_max) * 100;
	}

	cout << sum / N;


	return 0;
}