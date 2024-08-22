#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
int ans[2];
int main()
{
    // freopen("sample_input.txt", "r", stdin);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N); // 정렬 필수!

    int start = 0;        // start 은 왼쪽 끝에서
    int end = N - 1;      // end 은 오른쪽 끝에서 시작
    int min = 2000000000; // 현재까지 0 에 가장 가까웠던 합
    while (start < end)
    {
        int sum = arr[start] + arr[end];

        if (min > abs(sum))
        {
            min = abs(sum);
            ans[0] = arr[start];
            ans[1] = arr[end];

            if (sum == 0)
                break;
        }

        if (sum < 0)
            start++;
        else
            end--;
    }

    cout << ans[0] << " " << ans[1] << '\n';
    return 0;
}