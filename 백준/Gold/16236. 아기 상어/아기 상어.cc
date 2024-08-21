#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

/*
1. 입력을 받으면서 먹이의 크기와 위치를 벡터에 저장한다.
2. 자신보다 작은 크기의 먹이의 위치를 저장한다.
3. 큐를 이용해 BFS로 이동한다
4. 이동할때 걸리는 시간을 따로 저장한다.
5. 이동하면서 못하는 경우 리턴한다.
6. 타겟위치에 이동해서 먹으면 저장한 시간을 전체 시간에 저장한다.
7. 먹이 먹은 수가 크기와 같은지 확인하고 크기를 올린다.
*/

using namespace std;

struct target {
    int y, x, sz, dist;
};

struct Point {
    int y, x;
};

vector<target> t;

int N, M;
int map[20][20];
int sp_x, sp_y;
int s_sz = 2;
int flag, cnt;
int eat_cnt;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

bool cmp(target a, target b) {
    if (a.dist == b.dist) {
        if (a.y == b.y) {
            return a.x < b.x;
        }
        return a.y < b.y;
    }
    return a.dist < b.dist;
}

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];

            if (map[i][j] == 9) {
                sp_x = j;
                sp_y = i;
                map[i][j] = 0;
            }
        }
    }
}

void init(int y, int x) {
    t.clear();

    queue<Point> tp;
    tp.push({ y,x });

    int vis[20][20] = {};
    vis[y][x] = 1;
    while (!tp.empty()) {
        Point now = tp.front();
        tp.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];

            if (nx >= N || ny >= N || nx < 0 || ny < 0) continue;

            if (map[ny][nx] > s_sz) continue;

            if (vis[ny][nx] != 0) continue;

            //조건 수정하기
            if (map[ny][nx] != 0) {
                int dist = vis[now.y][now.x];
                t.push_back({ ny, nx , map[ny][nx], dist });
            }

            vis[ny][nx] = vis[now.y][now.x] + 1;
            tp.push({ ny,nx });
        }
    }

    if (t.size() == 0) {
        flag = 1;
        return;
    }
}

void solve() {
    target eat = {};

    //타겟 위치 잡는부분 수정하기
    for (int i = 0; i < t.size(); i++) {
        if (t[i].sz < s_sz) {
            eat.x = t[i].x;
            eat.y = t[i].y;
            eat.sz = t[i].sz;
            eat.dist = t[i].dist;
            t.erase(t.begin() + i);
            break;
        }
    }

    if (eat.sz == 0) {
        flag = 1;
        return;
    }

    eat_cnt++;
    if (eat_cnt == s_sz) {
        s_sz++;
        eat_cnt = 0;
    }

    sp_y = eat.y;
    sp_x = eat.x;

    map[eat.y][eat.x] = 0;
    cnt = cnt + eat.dist;
}

int main() {

    //freopen("sample.txt", "r", stdin);

    input();

    while (flag == 0) {
        init(sp_y, sp_x);
        sort(t.begin(), t.end(), cmp);
        solve();
    }

    cout << cnt;

    return 0;
}