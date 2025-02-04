#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int A[4001];
int B[4001];
int C[4001];
int D[4001];
vector<int> AB, CD;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	//배열 입력
	for (int i = 0; i < N; i++){
		cin >> A[i];
		cin >> B[i];
		cin >> C[i];
		cin >> D[i];
	}

	//A+B와 C+D 배열을 만든다
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			AB.push_back(A[i] + B[j]);
			CD.push_back(C[i] + D[j]);
		}
	}

	//이분탐색을 하기 위해 정렬
	sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end());


	long long int ans = 0;

	//AB에 담겨있는 숫자와 합해서 0이 되는 CD의 수 찾기
	//이분 탐색으로 탐색
	//upperbound, lowerbound 사용
	for (int i = 0; i < AB.size(); i++){
		int num_S = lower_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();
		int num_E = upper_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();

		ans += (num_E - num_S);
	}

	cout << ans;

	return 0;
}

