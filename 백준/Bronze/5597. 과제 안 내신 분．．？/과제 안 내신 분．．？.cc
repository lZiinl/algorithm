#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {

	int st[31] = { 0, };

	for (int i = 0; i < 28; i++){
		int temp;
		cin >> temp;
		st[temp] = 1;
	}

	for (int i = 1; i < 31; i++){
		if (st[i] == 0) {
			cout << i << "\n";
		}
	}

	return 0;
}