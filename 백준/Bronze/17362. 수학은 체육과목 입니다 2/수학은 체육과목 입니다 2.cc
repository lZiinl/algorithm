#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[8] = { 2, 1, 2, 3, 4, 5, 4, 3};

	int N;
	cin >> N;

	N %= 8;

	cout << arr[N];

	return 0;
}