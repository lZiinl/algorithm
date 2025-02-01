#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

//32

int main() {

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++){
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += 32;
		}
		else {
			s[i] -= 32;
		}
		cout << s[i];
	}

	return 0;
}