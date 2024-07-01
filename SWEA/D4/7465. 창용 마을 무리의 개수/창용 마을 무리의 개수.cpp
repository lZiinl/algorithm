#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include<vector>

using namespace std;

int N, M;
vector<int> v[101];
int vis[101];
int cnt;

void init(){
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < 101; i++){
		v[i].clear();
	}
}

void input(){
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
}

void solve(int sp){

	for (int i = 0; i < v[sp].size(); i++){
		if (vis[v[sp][i]] != 0) continue;

		vis[v[sp][i]] = cnt;
		solve(v[sp][i]);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("sample.txt", "r", stdin);
	
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++){
		init();
		input();
		cnt = 1;


		for (int i = 1; i <= N; i++){
			if (v[i].size() == 0) {
				cnt++;
				continue;
			}

			if (vis[i] != 0) continue;
			vis[i] = cnt;
			solve(i);
			cnt++;
		}
		cout << "#" << tc << " " << cnt - 1 << "\n";
	}
	
	return 0;
}