#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;

int N, M;

void input() {
    cin >> N >> M;
}

void solve() {

    int r = N * 60 + M;
    r = r - 45;

    if (r < 0) r = r + 24 * 60;

    cout << r / 60 << " " << r % 60;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("sample.txt", "r", stdin);

    input();
    solve();

    return 0;
}