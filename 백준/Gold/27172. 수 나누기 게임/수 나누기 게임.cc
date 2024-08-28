#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;

int N;
int num[100001];
int result[1000001];

void input() {
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> num[i];
    }
}

void solve() {
    for (int i = 0; i < N; i++)
    {
        // 자신의 약수들을 ++ 한다. (자기 자신 제외)
        if (num[i] != 1)
        {
            for (int j = 1; j * j <= num[i]; j++)
            {
                if (num[i] % j == 0)
                {
                    result[j]++;
                    if (j != 1 && j * j != num[i]) result[num[i] / j]++;
                }
            }
        }

        // 자신의 배수들을 --한다.
        for (int j = num[i] * 2; j < 1000001; j += num[i])
        {
            result[j]--;
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << result[num[i]] << " ";
    }
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