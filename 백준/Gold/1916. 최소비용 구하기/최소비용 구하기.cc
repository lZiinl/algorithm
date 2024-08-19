#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int sp, ep;
int dist[1001];

struct Node{
    int y, cost;
};

struct cmp
{
    bool operator() (Node a, Node b)
    {
        return a.cost > b.cost;
    }
};

vector<Node>edge[1001];

void input() {
    cin >> N >> M;
    
    for (int i = 0; i < M; i++){
        int from, to, c;

        cin >> from >> to >> c;
        edge[from].push_back({ to,c });
    }

    cin >> sp >> ep;
}

void solve() {

    priority_queue<Node, vector<Node>, cmp> pq;
    pq.push({ sp, 0 });
    dist[sp] = 0;

    while (!pq.empty()) {

        Node now = pq.top();
        pq.pop();

        if (dist[now.y] < now.cost) continue;

        for (int i = 0; i < edge[now.y].size(); i++){

            int nextCost = now.cost + edge[now.y][i].cost;
            int tar = edge[now.y][i].y;

            if (nextCost < dist[tar]) {
                dist[tar] = nextCost;
                pq.push({ tar, nextCost });
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

    for (int i = 0; i <= N; i++){
        dist[i] = 21e8;
    }

    solve();

    cout << dist[ep];

    return 0;
}