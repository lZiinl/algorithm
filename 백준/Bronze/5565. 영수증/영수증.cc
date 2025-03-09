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

    for (int i = 0; i < 9; i++){
        int tmp;
        cin >> tmp;

        N -= tmp;
    }
    cout << N;

    return 0;
}
