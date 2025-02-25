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
    N /= 4;

    for (int i = 0; i < N; i++){
        cout << "long ";
    }
    cout << "int";

    return 0;
}
