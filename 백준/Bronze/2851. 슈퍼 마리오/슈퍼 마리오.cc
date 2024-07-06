#include<iostream>
#include<cmath>

using namespace std;

int map[10];
int result;

int main() {

	for (int i = 0; i < 10; i++){
		cin >> map[i];
	}

	int cnt = 0;
	int sum = 0;

	while (cnt < 10) {
		sum += map[cnt];

		if (abs(100 - sum) <= abs(100 - result)) {

			result = sum;
			if (sum >= 100) break;
		}
		else {
			break;
		}
		cnt++;
	}

	cout << result;
	return 0;
}