#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {

		for (int i = 0; i < 3; i++){
			int t;
			cin >> t;
			arr.push_back(t);
		}

		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) break;

		sort(arr.begin(), arr.end());

		int a = arr[0] * arr[0] + arr[1] * arr[1];
		int b = arr[2] * arr[2];

		if (a == b) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}

		arr.clear();
	}

	return 0;
}

