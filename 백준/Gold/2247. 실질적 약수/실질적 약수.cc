#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    long long sum = 0;
    for (int i = 2; i <= N/2; i++){
        int cnt = N / i;
        sum += i * (cnt - 1);
    }

    cout << sum % 1000000;

    return 0;
}
