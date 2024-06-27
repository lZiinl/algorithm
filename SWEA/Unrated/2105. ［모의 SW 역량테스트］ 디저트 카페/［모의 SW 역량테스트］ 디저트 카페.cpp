#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
int N;
int MAP[20][20];
struct Point
{
	int y;
	int x;
};
// 메뉴의 합계
int sum;
// 정답
int ans;
// 공간 방문 체크
int visited[20][20];
// 메뉴 방문 체크
int DAT[101];
// 오른쪽 아래, 왼쪽 아래, 왼쪽위, 오른쪽 위
// 시계방향이며, 무조건 아랫쪽 먼저 시작
int dy[4] = { 1, 1, -1, -1 };
int dx[4] = { 1, -1, -1, 1 };

void init()
{
	memset(MAP, 0, sizeof(MAP));
	memset(visited, 0, sizeof(visited));
	memset(DAT, 0, sizeof(DAT));
	ans = -1;
	sum = 0;
}

void print(Point cp)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (cp.y == i && cp.x == j)
				cout << '@' << ' ';
			else
				cout << MAP[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> MAP[i][j];
}

void dfs(Point cp, Point sp, int dir, int isSp)
{
	// print()
	// 처음이 아니면서, 현재 좌표로 돌아왔다면
	if (!isSp && cp.y == sp.y && cp.x == sp.x)
	{
		if (sum > ans)
			ans = sum;
		return;
	}

	Point np = { cp.y + dy[dir], cp.x + dx[dir] };

	// 맵을 넘어가면
	if (np.y < 0 || np.x < 0 || np.y >= N || np.x >= N)
		return;
	// 이미 방문했다면
	if (visited[np.y][np.x] == 1)
		return;
	// 같은 메뉴라면
	if (DAT[MAP[np.y][np.x]] == 1)
		return;
	DAT[MAP[np.y][np.x]] = 1;
	visited[np.y][np.x] = 1;
	sum++;
	// 다른 방향으로 이동
	// 사각형 조건
	// dir == 2 번까지 갔다면, 한번 더 꺾을 수 있다는 뜻
	if (dir < 3)
	{
		dir++;
		dfs(np, sp, dir, 0);
		dir--;
	}
	// 같은 방향으로 이동
	dfs(np, sp, dir, 0);
	DAT[MAP[np.y][np.x]] = 0;
	visited[np.y][np.x] = 0;
	sum--;
}

void solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			dfs({ i, j }, { i, j }, 0, 1);
		}
	}
}

int main()
{
	//freopen("sample_input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();
		solve();
		cout << "#" << tc << " " << ans << '\n';
	}
}