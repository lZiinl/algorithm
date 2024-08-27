#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K;

int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

struct Node {
    int y, x, m, s, d;
};

queue<Node> map[52][52];

void input() {
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++){
        int t1, t2, t3, t4, t5;
        cin >> t1 >> t2 >> t3 >> t4 >> t5;
        map[t1][t2].push({t1, t2, t3, t4, t5 });
    }
}

void solve() {

    queue<Node> temp_q;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){

            int sz = map[i][j].size();
            int k = 0;

            while ( k++ < sz) {

                Node now = map[i][j].front();
                map[i][j].pop();

                int nc = (j + now.s * dx[now.d]) % N;
                int nr = (i + now.s * dy[now.d]) % N;

                if (nr < 1) nr += N;
                if (nc < 1) nc += N;
                if (nr > N) nr -= N;
                if (nc > N) nc -= N;

                temp_q.push({ nr, nc, now.m, now.s, now.d });
            }
        }
    }

    while (!temp_q.empty()) {
        Node now = temp_q.front();
        temp_q.pop();
        map[now.y][now.x].push({ now.y, now.x, now.m, now.s, now.d });
    }
}

void cal() {

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){

            if (map[i][j].size() < 2) continue;

            int msz = map[i][j].size();
            int sz = 0;
            int v = 0;
            int flag = 0;
            int pre_mod = -1;

            while (!map[i][j].empty()) {
                Node now = map[i][j].front();
                map[i][j].pop();

                sz += now.m;
                v += now.s;

                if (pre_mod == -1) {
                    pre_mod = now.d % 2;
                }
                else {
                    if (pre_mod != now.d % 2) {
                        flag = 1;
                    }
                }
            }

            v /= msz;
            sz /= 5;

            if (sz == 0) continue;

            if (flag == 1) {
                for (int k = 0; k < 4; k++){
                    map[i][j].push({ i, j, sz, v, k * 2 + 1 });
                }
            }
            else {
                for (int k = 0; k < 4; k++) {
                    map[i][j].push({ i, j, sz, v, k * 2 });
                }
            }
        }
    }
}

void result() {

    int sum = 0;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){

            while (!map[i][j].empty()) {
                Node now = map[i][j].front();
                map[i][j].pop();

                sum += now.m;
            }
        }
    }

    cout << sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("sample.txt", "r", stdin);

    input();

    for (int i = 0; i < K; i++){
        solve();
        cal();
    }

    result();

    return 0;
}