#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<char>C;
vector<char>result;


void input() {

	cin >> N >> M;
	C.resize(M);

	for (int i = 0; i < M; i++){
		cin >> C[i];
	}
}

void solve(int n, int level) {

	result.push_back(C[n]);
	
	if (level == N) {

		int cnt1 = 0, cnt2 = 0;

		for (int i = 0; i < N; i++){
			if (result[i] == 'a' || result[i] == 'e' || result[i] == 'i' || result[i] == 'o' || result[i] == 'u') cnt1++;
			else cnt2++;
		}

		if (cnt1 >= 1 && cnt2 >= 2) {
			for (int i = 0; i < N; i++) {
				cout << result[i];
			}
			cout << "\n";
		}
		return;
	}

	for (int i = n+1; i < M; i++){
		solve(i, level + 1);
		result.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("sample.txt", "r", stdin);

	input();
	sort(C.begin(), C.end());

	for (int i = 0; i <= M-N; i++){
		solve(i, 1);
		result.pop_back();
	}

	return 0;
}