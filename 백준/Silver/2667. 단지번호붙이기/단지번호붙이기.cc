#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

int N;
char map[26][26];
bool vis[26][26];

struct Node{
    int x, y;
};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<int>num;

void input() {
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> map[i];
    }
}

void bfs(int x, int y) {

    int cnt = 0;
    queue<Node>q;
    q.push({ x,y });
    vis[y][x] = true;

    while (!q.empty()) {

        Node now = q.front();
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++){

            int ny = now.y + dy[i];
            int nx = now.x + dx[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (vis[ny][nx] == true) continue;
            if (map[ny][nx] == '0') continue;

            vis[ny][nx] = true;
            q.push({ nx,ny });

        }
    }

    num.push_back(cnt);
}

void solve() {
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (vis[i][j] == true) continue;
            if (map[i][j] == '1') {
                bfs(j, i);
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

    sort(num.begin(), num.end());

    cout << num.size() << "\n";
    for (int i = 0; i < num.size(); i++){
        cout << num[i] << "\n";
    }

    return 0;
}