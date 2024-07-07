#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N, M;
int dat[10];

void input() {
    cin >> N >> M;
}

void solve() {
    
    for (int i = 1; i <= N; i++) {

        int num = i;

        while (num > 0) {

            dat[num % 10]++;
            num /= 10;
        }
    }
    cout << dat[M];
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