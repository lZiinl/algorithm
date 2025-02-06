#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> dp(500, -1);

long long fib(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	if (dp[n] != -1) return dp[n];

	return dp[n] = fib(n - 1) + fib(n - 2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	cout << fib(N);

	return 0;
	
}

