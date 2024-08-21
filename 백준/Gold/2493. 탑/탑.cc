#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>

using namespace std;

struct Node
{
	int ind, n;
};

stack<Node> s;
int N;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++){
		int temp;
		cin >> temp;
		
		while (!s.empty()) {

			Node now = s.top();

			if (now.n > temp) {
				cout << now.ind << " ";
				break;
			}
			else {
				s.pop();
			}
		}

		if (s.empty()) {
			cout << 0 << " ";
		}

		s.push({ i + 1, temp });
	}
}

void solve() {

	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("sample.txt", "r", stdin);

	input();
	//solve();

	return 0;
}