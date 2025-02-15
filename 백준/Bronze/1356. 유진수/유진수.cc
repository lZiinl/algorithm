#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string S;
	cin >> S;

	int len = S.length();
	//char n = '1';

	//cout << (int)n;

	for (int i = 0; i < len; i++){

		if (len == 1) continue;
		int s1 = 1;
		int s2 = 1;

		for (int j = 0; j <= i; j++){
			s1 *= (S[j] - 48);
		}

		for (int j = i+1; j < len; j++){
			s2 *= (S[j] - 48);
		}

		if (s1 == s2) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

	return 0;
}