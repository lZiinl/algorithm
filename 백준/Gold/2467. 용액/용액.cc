#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;

int N;
int arr[100001];

void input() {
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
}

void solve() {

    int left = 0;
    int right = N - 1;

    int s1, s2;
    s1 = arr[left];
    s2 = arr[right];

    int result = abs(arr[left] + arr[right]);

    while (left < right) {

        int sum = arr[left] + arr[right];
        int r = abs(arr[left] + arr[right]);

        if (result > r) {
            result = r;
            s1 = arr[left];
            s2 = arr[right];
        }

        if (sum > 0) right--;
        else if (sum < 0) left++;
        else {
            cout << arr[left] << " " << arr[right];
            return;
        }
    }
    cout << s1 << " " << s2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("sample.txt", "r", stdin);

    input();
    solve();

    return 0;
}