#define _CRT_SECURE_MO_WARNINGS
#include <iostream>

using namespace std;

int num;
int nmax = -21e8;
int nmin = 21e8;

void input() {
	cin >> num;
	int t;

	for (int i = 0; i < num; i++){
		cin >> t;

		if (t > nmax) {
			nmax = t;
		}
		
		if (t < nmin) {
			nmin = t;
		}
	}
	cout << nmin << " " << nmax;
}

void solve() {
	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	input();
	//solve();

	return 0;
}
