#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, S;
int vis[100001];

vector<int> v[100001];
int cnt = 1;

void dfs(int x);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> S;
	
	for (int i = 0; i < M; i++){
		int t1, t2;
		cin >> t1 >> t2;

		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}

	for (int i = 1; i <= N; i++){
		sort(v[i].begin(), v[i].end());
	}

	vis[S] = cnt;
	dfs(S);

	for (int i = 1; i <= N; i++){
		cout << vis[i] << "\n";
	}
}

void dfs(int x) {

	int size = v[x].size();

	for (int i = 0; i < size; i++){

		if (vis[v[x][i]] != 0) continue;

		cnt++;
		vis[v[x][i]] = cnt;
		dfs(v[x][i]);
	}
}