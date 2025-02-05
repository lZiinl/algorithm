#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {

		for (int i = 0; i < 3; i++){
			cin >> arr[i];
		}

		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) break;

		sort(arr, arr+size(arr));

		if ((arr[0] * arr[0] + arr[1] * arr[1]) == (arr[2] *arr[2])) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}
	}

	return 0;
}

