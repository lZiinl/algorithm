#include <iostream>

using namespace std;

int Euclidean(int a, int b)
{
	int r = a % b;
	if (r == 0) {
		return b;
	}
	return Euclidean(b, r);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++){
		int A, B;
		cin >> A >> B;

		int s = Euclidean(A, B);
		int e = A * B / s;

		cout << e << "\n";

	}

	return 0;
}