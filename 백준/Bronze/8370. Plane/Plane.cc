#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("sample.txt", "r", stdin);

    int N, M, J, K;
    cin >> N >> M >> J >> K;

    cout << N * M + J * K;

    return 0;
}
