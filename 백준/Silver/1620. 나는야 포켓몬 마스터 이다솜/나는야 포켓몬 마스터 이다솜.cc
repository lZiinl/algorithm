#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int N, M;
map<string, int> L;
vector<string> V;

void input() {
	cin >> N >> M;

	string name;
	V.push_back({ "start" });

	for (int i = 1; i <= N; i++){
		cin >> name;
		L.insert({ name , i });
		V.push_back(name);
	}
}


void solve() {
	
	string cmd;
	int num;

	for (int i = 0; i < M; i++){

		cin >> cmd;

		if (cmd[0] >= '0' && cmd[0] <= '9') {
			num = stoi(cmd);
			cout << V[num] << "\n";
		}
		else {
			cout << L[cmd] << "\n";
		}
	}

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
