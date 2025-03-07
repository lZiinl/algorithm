#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>v;
    int N;
    cin >> N;
    v.resize(N);

    for (int i = 0; i < N; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<>());

    for (int i = 0; i < N; i++){
        cout << v[i] << "\n";
    }

    return 0;
}
