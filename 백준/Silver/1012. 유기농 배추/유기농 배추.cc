#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

static int N, M;
static int map[51][51];
static bool vis[51][51];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct Node
{
    int y, x;
};

int pic_cnt;
int mmax;

void init() {
    pic_cnt = 0;
    memset(map, 0, sizeof(map));
    memset(vis, 0, sizeof(vis));
}

void input() {

    int num;
    cin >> N >> M >> num;

    for (int i = 0; i < num; i++)
    {
        int x, y;
        cin >> x >> y;
        map[y][x] = 1;
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

            if (ny < 0 || nx < 0 || nx >= N || ny >= M) continue;
            if (map[ny][nx] == 0) continue;
            if (vis[ny][nx] == true) continue;

            vis[ny][nx] = true;
            q.push({ ny,nx });
        }
    }

    if (mmax < cnt) mmax = cnt;
}

void search() {

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
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

    int tc = 0;
    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        init();
        input();
        search();
        cout << pic_cnt << "\n";
    }


    return 0;
}
