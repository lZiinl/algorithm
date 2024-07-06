#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

int N;
char v[20];
int res[2];

void input() {
    cin >> N;
    cin >> v;
}


void solve() {
    
    for (int i = 0; i < N; i++){
        if (v[i] == 'A') {
            res[0]++;
        }
        else {
            res[1]++;
        }
    }
   
    if (res[0] > res[1]) {
        cout << "A";
    }
    else if (res[0] < res[1]) {
        cout << "B";
    }
    else {
        cout << "Tie";
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