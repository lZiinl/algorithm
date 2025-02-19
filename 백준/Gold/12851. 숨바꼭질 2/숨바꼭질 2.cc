#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int N, K;
int map[200005];  
int cnt[200005];  

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    if (N == K) {
        cout << 0 << "\n" << 1;
        return 0;
    }

    queue<int> q;
    q.push(N);
    cnt[N] = 1; 

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < 3; i++) {
            int ny;

            if (i == 0) ny = now + 1;
            else if (i == 1) ny = now - 1;
            else ny = now * 2;

            if (ny < 0 || ny >= 200005) continue; 

            if (map[ny] == 0) { 
                map[ny] = map[now] + 1;
                cnt[ny] = cnt[now]; 
                q.push(ny);
            }
            else if (map[ny] == map[now] + 1) {
                cnt[ny] += cnt[now];
            }
        }
    }

    cout << map[K] << "\n" << cnt[K];

    return 0;
}
