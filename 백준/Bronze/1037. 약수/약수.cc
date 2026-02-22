#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	int N;
	cin >> N;

	vector<int> v;
	int a;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.begin() + v.size());

	long long int result = v[0] * v[N - 1];

	cout << result;

	return 0;
}