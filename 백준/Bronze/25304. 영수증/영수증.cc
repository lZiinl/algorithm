#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum;
    cin >> sum;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++){
        int t1, t2;
        cin >> t1 >> t2;

        sum -= (t1 * t2);
    }

    if (sum == 0) cout << "Yes";
    else {
        cout << "No";
    }

    return 0;
}
