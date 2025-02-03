#define _CRT_SERCURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int N;

void input() {

	cin >> N;

	vector<pair<int,int>> t(N);

	for (int i = 0; i < N; i++){
		cin >> t[i].second >> t[i].first;
	}

	sort(t.begin(), t.end());

	int cnt = 0;
	int end = -1;

	for (int i = 0; i < N; i++){
		if (t[i].second >= end) {
			end = t[i].first;
			cnt++;
		}
	}
	cout << cnt;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	return 0;
}