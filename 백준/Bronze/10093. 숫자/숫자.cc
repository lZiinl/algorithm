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

    if (N > M) {
        long long temp;
        temp = N;
        N = M;
        M = temp;
    }

    if (N == M) {
        cout << 0;
        return 0;
    }

    cout << M - N - 1 << "\n";
    for (long long i = N+1; i < M; i++)
    {
        cout << i << " ";
    }

    return 0;
}
