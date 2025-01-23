#define _CRT_SERCURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	int temp;
	for (int i = 0; i < N; i++){
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	cout << v[K - 1];

	return 0;
}