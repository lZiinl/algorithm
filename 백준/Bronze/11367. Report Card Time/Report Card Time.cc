#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("sample.txt", "r", stdin);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string S;
        int M;
        cin >> S >> M;

        cout << S;

        if (M >= 97) {
            cout << " A+\n";
        }
        else if (M >= 90) {
            cout << " A\n";
        }
        else if (M >= 87) {
            cout << " B+\n";
        }
        else if (M >= 80) {
            cout << " B\n";
        }
        else if (M >= 77) {
            cout << " C+\n";
        }
        else if (M >= 70) {
            cout << " C\n";
        }
        else if (M >= 67) {
            cout << " D+\n";
        }
        else if (M >= 60) {
            cout << " D\n";
        }
        else {
            cout << " F\n";
        }
    }

    return 0;
}
