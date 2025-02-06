#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	v.push_back(0);
	v.push_back(1);

	int N;
	cin >> N;

	for (int i = 2; i <= N; i++){
		v.push_back(v[i - 1] + v[i - 2]);
	}

	cout << v[N];

	return 0;
}

