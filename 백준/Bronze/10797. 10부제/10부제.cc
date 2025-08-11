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

    int N;
    cin >> N;
    int cnt = 0;

    for (int i = 1; i <= 5; i++)
    {
        int M;
        cin >> M;
        if (M == N) cnt++;
    }

    cout << cnt;

    return 0;
}
