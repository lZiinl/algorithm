#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int N;
int map[1000002] = {0, 1, 2, 3, 5, };

int main(){
	
	cin >> N;

	for (int i = 5; i <= N; i++){
		map[i] = (map[i - 2] + map[i - 1]) % 15746;
	}

	cout << map[N];

	return 0;
}