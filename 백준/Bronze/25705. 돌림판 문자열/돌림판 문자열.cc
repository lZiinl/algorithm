#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N, M;
char dol[101];
char ch[101];
int vis[30];
int flag;
int ind;

void input() {
    cin >> N;

    cin >> dol;

    for (int i = 0; i < N; i++){
        int num = dol[i] - 'a' + 1 ;
        vis[num] = num;
    }

    cin >> M;

    cin >> ch;

    for (int i = 0; i < M; i++) {
        int num = ch[i] - 'a' + 1;
        if (vis[num] == 0) {
            flag = 1;
        }
    }

}

void solve() {
    
    if (flag == 1) {
        cout << -1;
        return;
    }

    int cnt = 0;
    int n = 0;
    ind = 0;

    while (1) {
        
        for (int i = ind; i < N; i++){

            cnt++;

            if (dol[i] == ch[n]) {
                ind = (i + 1) % N;
                break;
            }

            if (i == N - 1) {
                i = -1;
            }
        }

        n++;
        if (n == M) {
            cout << cnt;
            return;
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

    return 0;
}