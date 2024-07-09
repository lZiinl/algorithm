#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int M, N;
int map[1001][1001];

int cnt;

struct Node{
    int y, x;
};

queue<Node>q;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void input() {
    cin >> M >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> map[i][j];
            if (map[i][j] == 1) {
                q.push({ i, j });
            }
        }
    }
}



void solve() {
    
    while (!q.empty()) {

        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){

            int ny = now.y + dy[i];
            int nx = now.x + dx[i];

            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if (map[ny][nx] != 0) continue;

            map[ny][nx] = map[now.y][now.x] + 1;
            q.push({ ny,nx });
            cnt = map[now.y][now.x];
        }
    }
}

void check() {
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (map[i][j] == 0) {
                cnt = -1;
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
    check();

    cout << cnt;

    return 0;
}