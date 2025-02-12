#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num[7] = { 0, };

	for (int i = 0; i < 3; i++){
		
		int n;
		cin >> n;
		num[n]++;
	}

	int ans = 0;
	for (int i = 1; i <= 6; i++){

		if (num[i] == 1) {
			if (ans < i * 100) ans = i * 100;
		}
		else if (num[i] == 2) {
			ans = 1000 + i * 100;
			break;
		}
		else if (num[i] == 3) {
			ans = 10000 + i * 1000;
			break;
		}
	}

	cout << ans;

	return 0;
}