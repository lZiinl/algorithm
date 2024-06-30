#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N, K;
int weight[9];
int cnt;
int vis[9];

void input() {
    cin >> N >> K;

    for (int i = 0; i < N; i++){
        cin >> weight[i];
    }
}

void dfs(int level, int ind, int hp) {

    hp += weight[ind];
    hp -= K;

    if (hp < 500) return;
    
    if (level == N) {
        cnt++;
        return;
    }
    
    for (int i = 0; i < N; i++) {
        if (vis[i] == 1) continue;
        vis[i] = 1;
        dfs(level + 1, i, hp);
        vis[i] = 0;
    }
}

void solve() {
    for (int i = 0; i < N; i++){
        vis[i] = 1;
        dfs(1, i, 500);
        vis[i] = 0;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("sample.txt", "r", stdin);

    input();
    solve();

    cout << cnt;

    return 0;
}