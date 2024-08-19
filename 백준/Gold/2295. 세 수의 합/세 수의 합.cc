#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int num[1001];
vector<int>sum;
int flag;

void input() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum.push_back(num[i] + num[j]);
        }
    }

    sort(num, num + N);
    sort(sum.begin(), sum.end());
}

void bs(int s) {

    int sp = 0;
    int ep = N - 1;

    while (ep > sp) {

        int temp = num[(sp + ep) / 2];

        if (s == temp) {
            flag = 1;
            return;
        }
        else if (s < temp) {
            ep = (sp + ep) / 2;
        }
        else {
            sp = (sp + ep) / 2 + 1;
        }
    }
}

void solve() {

    for (int i = N - 1; i >= 0; i--) {

        int tar = num[i];

        for (int j = 0; j < sum.size(); j++) {

            if (tar < sum[j]) break;

            bs(tar - sum[j]);

            if (flag == 1) {
                cout << num[i];
                return;
            }
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