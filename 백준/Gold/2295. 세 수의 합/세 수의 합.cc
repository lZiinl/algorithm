#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int num[1001];
vector<int> sum;
bool flag;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    sort(num, num + N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum.push_back(num[i] + num[j]);
        }
    }

    sort(sum.begin(), sum.end());
}

bool bs(int target) {
    int sp = 0;
    int ep = N - 1;

    while (sp <= ep) {
        int mid = (sp + ep) / 2;
        if (num[mid] == target) {
            return true;
        }
        if (num[mid] < target) {
            sp = mid + 1;
        } else {
            ep = mid - 1;
        }
    }
    return false;
}

void solve() {
    for (int i = N - 1; i >= 0; i--) {
        int tar = num[i];
        for (int j = 0; j < sum.size(); j++) {
            if (tar < sum[j]) break;
            if (bs(tar - sum[j])) {
                cout << num[i] << endl;
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    solve();

    return 0;
}
