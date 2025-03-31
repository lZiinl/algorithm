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

    if (N == 0) {
        cout << "YONSEI";
    }
    else {
        cout << "Leading the Way to the Future";
    }

    return 0;
}
