#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

int N, M;
int map[301][301];
int vis[301][301];
int nmap[301][301];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int flag;

struct Node{
    int y, x;
};

void input() {
    cin >> N >> M;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
}

void check() {

    int cnt = 0;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (map[i][j] == 0) {
                vis[i][j] = -1;
                continue;
            }

            if (vis[i][j] != 0) continue;

            cnt++;
            queue<Node>q;
            q.push({ i,j });
            vis[i][j] = cnt;

            flag = 1;
            if (cnt > 1) {
                flag = 2;
                return;
            }

            while (!q.empty()) {

                Node now = q.front();
                q.pop();

                for (int k = 0; k < 4; k++){

                    int ny = now.y + dy[k];
                    int nx = now.x + dx[k];

                    if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
                    if (vis[ny][nx] != 0) continue;
                    if (map[ny][nx] == 0) continue;

                    vis[ny][nx] = cnt;
                    q.push({ ny, nx });

                }
            }
        }
    }
}

void stage() {

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (map[i][j] == 0) continue;

            int y = i;
            int x = j;
            int n_cnt = 0;

            for (int k = 0; k < 4; k++){
                int ny = y + dy[k];
                int nx = x + dx[k];

                if (map[ny][nx] != 0) continue;
                n_cnt++;
            }

            nmap[y][x] =  n_cnt;
        }
    }
}

void del() {
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            map[i][j] -= nmap[i][j];

            if (map[i][j] < 0) {
                map[i][j] = 0;
            }
        }
    }
}

void solve() {
    int cnt = 0;

    while (1) {
        flag = 0;

        memset(vis, 0, sizeof(vis));
        memset(nmap, 0, sizeof(nmap));
        check();

        if (flag == 0) {
            cout << 0;
            return;
        }
        else if (flag == 2) {
            cout << cnt;
            return;
        }

        stage();
        del();
        cnt++;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("sample.txt", "r", stdin);

    input();
    solve();

    return 0;
}