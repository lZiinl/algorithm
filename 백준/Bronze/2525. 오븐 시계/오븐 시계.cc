#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[2] = {};
    for (int i = 0; i < 2; i++){
        cin >> arr[i];
    }

    int N;
    cin >> N;
    arr[1] += N;

    int t = arr[1] / 60;
    arr[1] %= 60;
    
    arr[0] += t;
    arr[0] %= 24;

    cout << arr[0] << " " << arr[1];

    return 0;
}
