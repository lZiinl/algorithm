#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int sum = 0;
    sum += N / 5;
    sum += N / 25;
    sum += N / 125;

    cout << sum;

    return 0;
}
