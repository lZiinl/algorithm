#include<iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B;
	cin >> A >> B;

	int an_1 = A % 10;
	A = A / 10;
	int an_10 = A % 10;
	A = A / 10;
	int an_100 = A % 10;
	A = A / 10;

	A = an_1 * 100 + an_10 * 10 + an_100;

	int bn_1 = B % 10;
	B = B / 10;
	int bn_10 = B % 10;
	B = B / 10;
	int bn_100 = B % 10;
	B = B / 10;

	B = bn_1 * 100 + bn_10 * 10 + bn_100;

	if (A > B) {
		cout << A;
	}
	else if (B > A) {
		cout << B;
	}

	return 0;
}