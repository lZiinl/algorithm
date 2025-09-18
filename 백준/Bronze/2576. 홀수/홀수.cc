#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);
	
	int arr[7] = { 0, };
	for (int i = 0; i < 7; i++)
	{
		cin >> arr[i];
	}

	int sum = 0;
	int num_min = 999;

	for (int i = 0; i < 7; i++)
	{
		if ((arr[i] % 2) == 1) {
			sum += arr[i];

			if (arr[i] < num_min) {
				num_min = arr[i];
			}
		}
	}

	if (num_min == 999) {
		cout << -1;
	}
	else {
		cout << sum << "\n" << num_min;
	}

	return 0;
}