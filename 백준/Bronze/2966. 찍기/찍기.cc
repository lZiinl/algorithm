#include <iostream>
#include <string>

using namespace std;

char a[3] = { 'A', 'B', 'C' };
char b[4] = { 'B', 'A', 'B', 'C' };
char c[6] = { 'C', 'C', 'A', 'A', 'B', 'B' };

int arr[3];
string name[3] = { "Adrian", "Bruno", "Goran" };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	string s;
	cin >> s;

	for (int i = 0; i < 3; i++){

		if (i == 0) {
			for (int j = 0; j < N; j++) {
				int k = j % 3;
				if (s[j] == a[k]) {
					arr[i]++;
				}
			}
		}

		if (i == 1) {
			for (int j = 0; j < N; j++) {
				int k = j % 4;
				if (s[j] == b[k]) {
					arr[i]++;
				}
			}
		}

		if (i == 2) {
			for (int j = 0; j < N; j++) {
				int k = j % 6;
				if (s[j] == c[k]) {
					arr[i]++;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 3; i++){

		if (ans < arr[i]) {
			ans = arr[i];
		}
	}

	cout << ans << "\n";

	for (int i = 0; i < 3; i++){
		if (ans == arr[i]) {
			cout << name[i] << "\n";
		}
	}

}