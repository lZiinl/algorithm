#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int N;
int number[4000001];
vector<int> v;

void input() {
    cin >> N;

    for (int i = 2; i <= N; i ++){
        if (number[i] != 0) {
            number[i]++;
            continue;
        }

        for (int j = i; j <= N; j += i){
            number[j]++;
        }
    }

    for (int i = 2; i <= N; i++){
        if (number[i] == 1) {
            v.push_back(i);
        }
    }
}

void solve() {
    
    if (N == 1) {
        cout << 0;
        return;
    }

    int sum = 0;
    int sp = 0;
    int ep = 0;
    int ans = 0;

    while (ep <= v.size()) {


        if (sum >= N) {
            sum -= v[sp];
            sp++;
        }

        if (sum < N) {
            if (ep == v.size()) {
                break;
            }

            sum += v[ep];
            ep++;
        }

        if (sum == N) ans++;
    }

    cout << ans;
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