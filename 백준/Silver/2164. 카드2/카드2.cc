#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int N;

void input() {
    cin >> N;
}

void solve() {
    queue<int>q;

    for (int i = 1; i <= N; i++){
        q.push(i);
    }

    int cnt = 1;

    while (1) {

        int num = q.front();

        if (q.size() == 1) {
            cout << num;
            return;
        }

        q.pop();
        if (cnt % 2 == 0) {
            q.push(num);
        }
        cnt++;
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
