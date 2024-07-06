#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<queue>

using namespace std;

int C, N;
vector<int>edge[101];
int vis[101];
int cnt;

void input() {
    cin >> C >> N;

    for (int i = 0; i < N; i++){
        int from, to;
        cin >> from >> to;

        edge[from].push_back(to);
        edge[to].push_back(from);
    }
}

void solve() {
    
    queue<int>q;
    q.push(1);

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        vis[now] = 1;
        cnt++;

        for (int i = 0; i < edge[now].size(); i++){

            if (vis[edge[now][i]] == 1) continue;
            vis[edge[now][i]] = 1;
            q.push(edge[now][i]);

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

    cout << cnt - 1;
    return 0;
}