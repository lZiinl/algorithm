#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;

int N, X;
int arr[10001];

void input() {
    cin >> N >> X;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
}

void solve() {

    for (int i = 0; i < N; i++){
        if (arr[i] < X) {
            cout << arr[i] << " ";
        }
    }
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