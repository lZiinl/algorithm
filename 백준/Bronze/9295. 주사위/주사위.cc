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

    for (int i = 1; i <= N; i++){
        int A, B;
        cin >> A >> B;

        cout << "Case " << i << ": " << A + B << "\n";
    }

    return 0;
}
