#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("sample.txt", "r", stdin);

    long long N, M;
    cin >> N >> M;

    if (N == M) {
        cout << "1";
    }
    else {
        cout << "0";
    }

    return 0;
}
