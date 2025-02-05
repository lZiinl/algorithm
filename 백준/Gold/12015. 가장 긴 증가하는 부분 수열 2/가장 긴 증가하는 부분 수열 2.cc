#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1000001];
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;
    cin >> N;

    
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++){
        int num = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();

        if (num == v.size()) {
            v.push_back(arr[i]);
        }
        else {
            v[num] = arr[i];
        }

    }

    cout << v.size();

	return 0;
}

