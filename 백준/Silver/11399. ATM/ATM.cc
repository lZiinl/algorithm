#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> t;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++){
		int temp;
		cin >> temp;
		t.push_back(temp);
	}

	sort(t.begin(), t.end());

	int sum = 0;
	int s = N;
	for (int i = 0; i < N; i++){
		sum += t[i] * s;
		s--;
	}
	cout << sum;
}

void solve() {
	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	input();
	//solve();

	return 0;
}
