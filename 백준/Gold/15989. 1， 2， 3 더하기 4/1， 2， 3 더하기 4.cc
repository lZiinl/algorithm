#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int T, N;
int map[10001] = {0, 1, 2, 3, 4, };

int main(){
	
	cin >> T;

	for (int i = 0; i < T; i++){
		cin >> N;

		for (int i = 5; i <= N; i++){
			map[i] = 1 + i / 2 + map[i - 3];
		}

		cout << map[N] << "\n";
	}

	return 0;
}