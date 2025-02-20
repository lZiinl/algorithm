#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include<vector>

using namespace std;

int N, K;
int map[200005];
int cnt[200005];

void bfs() {
    queue<int> q;
    q.push(N);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < 3; i++) {
            int ny;

            if (i == 0) ny = now + 1;
            else if (i == 1) ny = now - 1;
            else ny = now * 2;

            if (ny < 0 || ny >= 200005) continue;
            if (map[ny] != -1) continue;

            cnt[ny] = cnt[now] + 1;
            map[ny] = now;
            q.push(ny);

            if (ny == K) return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    if (N == K) {
        cout << 0 << "\n" << N;
        return 0;
    }

    for (int i = 0; i < 200005; i++) {
        map[i] = -1;
    }

    map[N] = N;
    bfs();

    vector<int>v;
    v.push_back(K);
    for (int i = 0; i < cnt[K]; i++) {
        v.push_back(map[v[i]]);
    }

    cout << cnt[K] << "\n";
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }

    return 0;
}
