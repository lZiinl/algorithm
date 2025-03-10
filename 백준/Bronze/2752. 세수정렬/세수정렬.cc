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

    for (int i = 0; i < 3; i++){
        int tmp;
        cin >> tmp;

        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < 3; i++){
        cout << v[i] << " ";
    }

    return 0;
}
