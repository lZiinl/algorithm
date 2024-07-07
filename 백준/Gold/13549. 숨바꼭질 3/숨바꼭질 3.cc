#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, k;

int bfs(int n, int k)
{
	if (n >= k)
		return n - k;

	queue<int> q;
	q.push(n);

	vector<int> v(100001, -1);
	v[n] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == k)
			return v[cur];


		for (int next : {cur + 1, cur - 1, cur * 2})
		{
			if (next < 0 || next > 100000)
				continue;

			// 아직 방문 안한 경우
			if (v[next] == -1)
			{
				if (next == cur * 2)
					v[next] = v[cur];
				else
					v[next] = v[cur] + 1;

				q.push(next);
				continue;
			}

			// 방문했지만, 더 빨리갈 수 있는 경우
			if (next == cur * 2)
			{
				if (v[next] > v[cur])
					v[next] = v[cur];
			}
			else
			{
				if (v[next] > v[cur] + 1)
					v[next] = v[cur] + 1;
			}
		}
	}
}

int main()
{
	int n, k;
	cin >> n >> k;

	cout << bfs(n, k);

	return 0;
}