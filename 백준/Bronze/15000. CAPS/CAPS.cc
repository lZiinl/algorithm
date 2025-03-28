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

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        cout << char(s[i] - 32);
    }

    return 0;
}
