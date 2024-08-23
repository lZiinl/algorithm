#define _CRT_SECURE_MO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int T;
int n;
char c[22];

void input() {
	cin >> T;

	for (int t = 0; t < T; t++){
		cin >> n >> c;

		for (int i = 0; i < strlen(c); i++){
			for (int j = 0; j < n; j++){
				cout << c[i];
			}
		}
		cout << "\n";
	}
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
