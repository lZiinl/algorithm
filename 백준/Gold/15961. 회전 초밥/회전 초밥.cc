#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

using namespace std;

int N, D, K, C;
int sushi[3000001];
int eat[3001];
int result;

void input() {
	cin >> N >> D >> K >> C;

	for (int i = 0; i < N; i++) {
		cin >> sushi[i];
	}
}

void solve() {
	queue<int> q;
	int t_cnt = 0;
	for (int i = 0; i < K; i++) {
		q.push(sushi[i]);
		t_cnt++;
		eat[sushi[i]]++;

		if (sushi[i] == C) {
			t_cnt--;
			continue;
		}

		if (eat[sushi[i]] > 1) {
			t_cnt--;
		}
	}

	int max_cnt = t_cnt;

	for (int i = K; i < N + K - 1; i++) {

		int t = q.front();
		q.pop();
		eat[t]--;

		if (eat[t] == 0) {
			t_cnt--;
		}

		if (t == C && eat[C] == 0) {
			t_cnt++;
		}

		q.push(sushi[i % N]);
		t_cnt++;
		if (eat[sushi[i % N]] != 0) {
			t_cnt--;
		}

		if (sushi[i % N] == C && eat[C] == 0) {
			t_cnt--;
		}

		eat[sushi[i % N]]++;

		if (t_cnt > max_cnt) {
			max_cnt = t_cnt;
		}
	}

	result = max_cnt + 1;
}

int main() {

	//freopen("sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	cout << result;

	return 0;
}