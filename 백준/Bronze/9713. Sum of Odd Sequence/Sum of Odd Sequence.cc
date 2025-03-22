#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Y;
    cin >> Y;

    for (int i = 0; i < Y; i++){
        
        int sum = 0;
        int N;
        cin >> N;

        for (int j = 0; j < N/2 +1; j++){
            sum += j * 2 + 1;
        }
        cout << sum << "\n";
    }

    return 0;
}
