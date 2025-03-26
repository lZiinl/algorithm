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

    for (int i = 0; i < N; i++)
    {
        string S;
        cin >> S;

        int M = 1;
        int sum = 0;
        for (int j = S.length()-1; j >= 0; j--)
        {
            if (S[j] == '1') {
                sum += M;
            }
            M *= 2;
        }
        cout << sum << "\n";
    }


    return 0;
}
