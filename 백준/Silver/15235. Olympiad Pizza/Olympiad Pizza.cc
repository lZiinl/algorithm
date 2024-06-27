#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int N;
int arr[1001];
int eat[1001];
int tim[1001];

void input() {
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
}

void solve() {
    int cnt = 1;

    queue<int> q;

    for (int i = 0; i < N; i++){
        q.push(i);
    }

    while (!q.empty()) {

        int ct = q.front();
        q.pop();

        eat[ct]++;

        if (eat[ct] < arr[ct]) {
            q.push(ct);
        }
        else {
            tim[ct] = cnt;
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

    for (int i = 0; i < N; i++){
        cout << tim[i] << " ";
    }

    return 0;
}
