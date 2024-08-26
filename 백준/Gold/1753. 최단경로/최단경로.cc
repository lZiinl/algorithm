#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E;
int S; // 시작점

struct Node
{
	int num, cost;
};

vector<Node> v[20001];
int dist[20001];

struct cmp
{
	bool operator()(Node a, Node b) {
		return a.cost > b.cost;
	}
};

void input() {
	cin >> V >> E >> S;

	for (int i = 0; i < E; i++){
		int from, to, c;
		cin >> from >> to >> c;
		v[from].push_back({ to, c });
	}

	for (int i = 1; i <= V; i++){
		dist[i] = 21e8;
	}
}


void solve() {
	
	priority_queue<Node, vector<Node>, cmp> pq;
	pq.push({ S, 0 });
	dist[S] = 0;

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
	solve();

	for (int i = 1; i <= V; i++){

		if (dist[i] == 21e8) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}

	return 0;
}