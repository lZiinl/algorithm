#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int arr[1001];
int N;

int main() {

	cin >> N;

	arr[1] = 1;
	arr[2] = 2;

	for (int i = 3; i <= N; i++){
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}

	cout << arr[N];

	return 0;
}