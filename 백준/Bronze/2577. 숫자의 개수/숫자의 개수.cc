#include<iostream>

using namespace std;

int num[10];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, C;
	long long result;

	cin >> A >> B >> C;
	result = A * B * C;

	while (result > 0) {
		int t = result % 10;
		num[t]++;
		result = result / 10;
	}

	for (int i = 0; i < 10; i++){
		cout << num[i] << endl;
	}

	return 0;
}