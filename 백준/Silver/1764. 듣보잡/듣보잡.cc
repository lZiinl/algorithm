#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

int N, M;
int cnt;

map<string, bool> L;
vector<string> V;

void input() {
	cin >> N >> M;

	string s;

	for (int i = 0; i < N; i++){
		cin >> s;
		L.insert({ s, true });
	}

	for (int i = 0; i < M; i++){
		cin >> s;
		if (L[s]) {
			V.push_back(s);
			cnt++;
		}
	}

	sort(V.begin(), V.end());
	
	cout << cnt << "\n";
	for (int i = 0; i < V.size(); i++){
		cout << V[i] << "\n";
	}
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
