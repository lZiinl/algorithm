#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

using namespace std;

static int N, M;
static int map[501][501];
static bool vis[501][501];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct Node
{
    int y, x;
};

int pic_cnt;
int mmax;

void input() {

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }
}

void bfs(int y, int x) {

    vis[y][x] = true;
    queue<Node> q;
    q.push({ y, x });
    int cnt = 0;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (map[ny][nx] == 0) continue;
            if (vis[ny][nx] == true) continue;

            vis[ny][nx] = true;
            q.push({ ny,nx });
        }
    }

    if (mmax < cnt) mmax = cnt;
}

void search() {

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 0) continue;
            if (vis[i][j] == true) continue;
            
            pic_cnt++;

            bfs(i, j);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("sample.txt", "r", stdin);

    input();

    search();

    cout << pic_cnt << "\n" << mmax;

    return 0;
}
