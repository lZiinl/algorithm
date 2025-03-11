#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	
	while (1) {
		int t1, t2;
		cin >> t1 >> t2;

		if (t1 == 0 && t2 == 0) return 0;

		if (t1 > t2) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}


	return 0;
}