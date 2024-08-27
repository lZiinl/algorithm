#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;

int N;

void input() {
    cin >> N;
}

void print1(int n) {
    for (int i = 0; i < n; i++){
        cout << " ";
    }
}

void print2(int n) {
    for (int i = 0; i < n; i++) {
        cout << "*";
    }
}

void solve() {

    for (int i = 1; i <= N; i++){
        
        print1(N - i);
        print2(i);

        cout << endl;
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