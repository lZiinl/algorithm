#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
vector<int>v;
long long ans;

void input() {
	cin >> N;

	v.resize(N);

	for (int i = 0; i < N; i++){
		cin >> v[i];
	}

	sort(v.begin(), v.end());
}

void solve() {

	for (int i = 0; i < N-1; i++){
		for (int j = i+1; j < N; j++){

			int find = v[i] + v[j];
			int lower = lower_bound(v.begin() + j + 1, v.end(), -find) - v.begin();
			int upper = upper_bound(v.begin() + j + 1, v.end(), -find) - v.begin();
			
            ans += upper - lower;
		}
	}
	cout << ans;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	input();
	solve();

	return 0;
}
