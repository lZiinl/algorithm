#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

string s;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	cin >> s;

	for (int i = 0; i < s.length(); i++){
		if (s[i] != s[s.length() - 1 - i]) {
			cout << 0;
			return 0;
		}
	}
	
	cout << 1;
	return 0;
}
