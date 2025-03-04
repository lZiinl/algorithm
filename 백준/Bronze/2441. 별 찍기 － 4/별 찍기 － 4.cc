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

    for (int i = 0; i < N; i++){

        for (int j = 0; j < i; j++) {
            cout << " ";
        }

        for (int j = i; j < N; j++){
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
