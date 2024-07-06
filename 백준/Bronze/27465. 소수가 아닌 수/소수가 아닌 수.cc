#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

long long int N;

void input() {
    cin >> N;
}

void solve() {
    if (N == 2 || N==1) {
        cout << 4;
    }
    else if (N % 2 == 0) {
        cout << N + 2;
    }
    else {
        cout << N + 1;
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