#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int N;

struct Node
{
    int x, y;
};

vector<Node> v;

void input() {
    cin >> N;

    for (int i = 0; i < N; i++){
        int t1, t2;
        cin >> t1 >> t2;
        v.push_back({ t1,t2 });
    }
}

long double solve(int i, int j) {
    long double a = v[0].x, b = v[0].y;
    long double c = v[i].x, d = v[i].y;
    long double e = v[j].x, f = v[j].y;

    return (a * d + c * f + e * b - c * b - e * d - a * f) / 2;
}

void solve() {   
    long double ans = 0;
    for (int i = 1; i < N - 1; i++) {
        ans += solve(i, i + 1);
    }

    cout.precision(1);
    cout << fixed;
    cout << abs(ans) << endl;
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