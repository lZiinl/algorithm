#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int N, E;
int S, F;

struct Node
{
	int num, cost;
};

vector<Node> v[801];
int dist[801];

struct cmp
{
	bool operator()(Node a, Node b) {
		return a.cost > b.cost;
	}
};

void input() {
	cin >> N >> E;

	for (int i = 0; i < E; i++){
		int from, to, c;
		cin >> from >> to >> c;
		v[from].push_back({ to, c });
		v[to].push_back({ from, c });
	}

	cin >> S >> F;
}


void solve(int a) {
	
	for (int i = 1; i <= N; i++) {
		dist[i] = 9000000;
	}

	priority_queue<Node, vector<Node>, cmp> pq;
	pq.push({ a, 0 });
	dist[a] = 0;

	while (!pq.empty()) {

		Node now = pq.top();
		pq.pop();

		if (dist[now.num] < now.cost) continue;

		for (int i = 0; i < v[now.num].size(); i++){

			int nextcost = now.cost + v[now.num][i].cost;
			int tar = v[now.num][i].num;

			if (dist[tar] > nextcost) {
				dist[tar] = nextcost;
				pq.push({ tar, nextcost });
			}
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
	int to_S = dist[S];
	int to_F = dist[F];

	solve(S);
	int S_to_F = dist[F];
	int S_to_N = dist[N];

	solve(F);
	int F_to_N = dist[N];

	int sum1 = to_S + S_to_F + F_to_N;
	int sum2 = to_F + S_to_F + S_to_N;

	int res = min(sum1, sum2);

	if (res >= 9000000) {
		cout << -1;
	}
	else {
		cout << res;
	}

	return 0;
}