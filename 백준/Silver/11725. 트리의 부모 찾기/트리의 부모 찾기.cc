#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int>v[100001];
int arr[100001];
bool visited[100001];

void input() {
	cin >> N;

	for (int i = 0; i < N-1; i++){
		int t1, t2;
		cin >> t1 >> t2;

		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
}

void solve(int k) {

	visited[k] = true;

	for (int i = 0; i < v[k].size(); i++) {

		int next = v[k][i];

		if (!visited[next]) {
			arr[next] = k;
			solve(next);
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	input();
	solve(1);

	for (int i = 2; i <= N; i++){
		cout << arr[i] << "\n";
	}

	return 0;
}
