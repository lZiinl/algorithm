#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {

		int N;
		cin >> N;

		if (N == 0) return 0;

		int ans = 0;

		while (1) {
			int num = N % 10;

			if (num == 1) {
				ans += 3;
			}
			else if (num == 0) {
				ans += 5;
			}
			else {
				ans += 4;
			}

			N /= 10;
			if (N == 0) {
				cout << ans + 1 << "\n";
				break;
			}
		}

	}

}