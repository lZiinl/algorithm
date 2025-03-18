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

    int Y, M;
    cin >> Y >> M;
    
    if (3 <= Y && M <= 4) {
            cout << "TroyMartian\n";
    }

    if (2 <= M && Y <= 6) {
            cout << "VladSaturnian\n";
    }

    if (Y <= 2 && M <= 3) {
            cout << "GraemeMercurian\n";
    }

    return 0;
}
