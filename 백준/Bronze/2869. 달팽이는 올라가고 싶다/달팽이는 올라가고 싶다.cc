#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, V;
	cin >> A >> B >> V;

	if (A >= V) {
		cout << "1";
	}
	else {

		int ans = 1;
		ans += (V - A) / (A - B);

		if ((V - A) % (A - B) != 0) {
			ans++;
		}

		cout << ans;
	}

	return 0;

}

