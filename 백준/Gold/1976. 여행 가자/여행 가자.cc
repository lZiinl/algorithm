#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> edge[202];
int city[1002];
bool vis[202];

void input() {
    cin >> N >> M;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            int temp;
            cin >> temp;

            if (temp == 1) {
                edge[i+1].push_back(j+1);
                edge[j + 1].push_back(i + 1);
            }
        }
    }

    for (int i = 0; i < M; i++){
        cin >> city[i];
    }
}

void solve() {
    
    queue<int>q;
    q.push(city[0]);
    vis[city[0]] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < edge[now].size(); i++){
            if (vis[edge[now][i]] == true) continue;
            q.push(edge[now][i]);
            vis[edge[now][i]] = true;
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

    for (int i = 0; i < M; i++){
        if (vis[city[i]] == false) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}