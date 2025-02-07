#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int arr[5001];
int N;
int num[2] = { 3, 5 };

int main() {

	cin >> N;

	memset(arr, -1, sizeof(arr));

	for (int i = 1; i <= N; i++){

		if (i == 3 || i == 5) arr[i] = 1;

		if (arr[i] > 0) {

			for (int j = 0; j < 2; j++){
				int ny = i + num[j];
				if (ny > N) continue;

				if (arr[ny] == -1) arr[ny] = arr[i] + 1;
				else arr[ny] = min(arr[ny], arr[i] + 1);
			}
		}
	}

	cout << arr[N];

	return 0;
}