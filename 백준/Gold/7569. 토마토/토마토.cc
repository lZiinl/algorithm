#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int M, N, H;
int map[101][101][101];

int cnt;

struct Node{
    int x, y, z;
};

queue<Node>q;

int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

void input() {
    cin >> M >> N >> H;

    for (int i = 0; i < H; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < M; k++){
                cin >> map[i][j][k];
                if (map[i][j][k] == 1) {
                    q.push({ k, j, i });
                }
            }
        }
    }
}

void solve() {
    
    while (!q.empty()) {

        Node now = q.front();
        q.pop();

        for (int i = 0; i < 6; i++){

            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            int nz = now.z + dz[i];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= M || ny >= N || nz >= H) continue;
            if (map[nz][ny][nx] != 0) continue;

            map[nz][ny][nx] = map[now.z][now.y][now.x] + 1;
            q.push({ nx, ny, nz });
            cnt = map[now.z][now.y][now.x];
        }
    }
}

void check() {
    for (int i = 0; i < H; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < M; k++){
                if (map[i][j][k] == 0) {
                    cnt = -1;
                }
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