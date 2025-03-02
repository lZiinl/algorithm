#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

string s1, s2;
double c;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	double sum = 0;
	double s = 0;
	for (int i = 0; i < 20; i++){
		cin >> s1 >> c >> s2;

		if (s2[0] == 'P') continue;

		sum += c;

		if (s2[0] == 'A') {

			if (s2[1] == '+') s += c * 4.5;
			else s += c * 4.0;

		}
		else if (s2[0] == 'B') {

			if (s2[1] == '+') s += c * 3.5;
			else s += c * 3.0;

		}
		else if (s2[0] == 'C') {

			if (s2[1] == '+') s += c * 2.5;
			else s += c * 2.0;

		}
		else if (s2[0] == 'D') {

			if (s2[1] == '+') s += c * 1.5;
			else s += c * 1.0;

		}

	}
	
	cout << s/sum;
	return 0;
}
