#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>v;
    v.resize(3);

    for (int i = 0; i < 3; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    cout << v[1];

    return 0;
}
