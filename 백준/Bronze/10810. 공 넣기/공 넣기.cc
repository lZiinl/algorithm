#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int arr[101] = {};

    for (int i = 0; i < M; i++){

        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;

        for (int j = t1; j <= t2; j++){
            arr[j] = t3;
        }

    }

    for (int i = 1; i <= N; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
