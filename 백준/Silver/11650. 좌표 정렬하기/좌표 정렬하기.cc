#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int x, y;
};

bool cmp(Node a, Node b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<Node>v;
    int N;
    cin >> N;
    v.resize(N);

    for (int i = 0; i < N; i++){
        cin >> v[i].x >> v[i].y;
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++){
        cout << v[i].x << " " << v[i].y << "\n";
    }

    return 0;
}
