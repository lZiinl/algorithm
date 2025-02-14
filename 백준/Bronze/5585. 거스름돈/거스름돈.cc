#include <iostream>

using namespace std;

int arr[] = { 500, 100, 50, 10, 5, 1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	int num = 1000 - N;
	int ans = 0;

	for (int i = 0; i < 6; i++){

		ans += num / arr[i];
		num %= arr[i];
	}

	cout << ans << "\n";

}