#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N;
int map[101][101];
long long int dp[101][101];

int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };

void input() {
    cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }
    dp[0][0] = 1;
}

void solve() {
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){

            if (dp[i][j] == 0) continue;
            if (i == N - 1 && j == N - 1) continue;

            for (int k = 0; k < 2; k++){

                int nx = j + dx[k] * map[i][j];
                int ny = i + dy[k] * map[i][j];

                if (nx >= N || ny >= N) continue;

                dp[ny][nx] = dp[ny][nx] + dp[i][j];

            }
        }
    }

    cout << dp[N - 1][N - 1];
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