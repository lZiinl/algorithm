#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int map[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("sample.txt", "r", stdin);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> map[i];
    }

    int sc = 0;
    int result = 0;

    for (int i = 0; i < N; i++)
    {
        if (map[i] == 1) {
            sc++;
            result += sc;
        }
        else {
            sc = 0;
        }
    }

    cout << result;

    return 0;
}
