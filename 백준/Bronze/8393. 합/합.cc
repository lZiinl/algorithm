#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int sum = 0;

	for (int i = 1; i <= N; i++){
		
		sum += i;

	}

	cout << sum;

	return 0;
}