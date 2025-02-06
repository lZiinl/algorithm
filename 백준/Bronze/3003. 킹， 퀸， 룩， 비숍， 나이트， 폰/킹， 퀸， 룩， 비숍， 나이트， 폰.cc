#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[6] = { 1, 1, 2, 2, 2, 8 };

	int inarr[6] = { 0, };
	for (int i = 0; i < 6; i++){
		cin >> inarr[i];
	}
    
	for (int i = 0; i < 6; i++){
		cout << arr[i] - inarr[i] << " ";
	}

	return 0;
}

