#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int main() {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++){
		string S;
		cin >> S;

		cout << S[0] << S[S.length() - 1] << "\n";
	}

	return 0;
}