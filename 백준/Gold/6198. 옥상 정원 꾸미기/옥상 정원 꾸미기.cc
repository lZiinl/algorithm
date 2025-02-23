#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>

using namespace std;

int N;
stack<int>s;

void solve() {

	long long ans = 0;
	for (int i = 0; i < N; i++){

		int t;
		cin >> t;

		if (s.empty()) {
			s.push(t);
			continue;
		}

		while (!s.empty() && s.top() <= t) {
			s.pop();
		}

		ans += s.size();
		s.push(t);
	}

	cout << ans;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	cin >> N;

	solve();
	

	return 0;
}
