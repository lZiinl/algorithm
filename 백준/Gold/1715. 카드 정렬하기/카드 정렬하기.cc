#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

using namespace std;

int N;
int result;

struct Num {
    int cost;
    bool operator<(Num right) const {
        if (cost < right.cost) return false;
        if (cost > right.cost) return true;
        return false;
    }
};

priority_queue<Num>pq;

void solve() {
    auto a = pq.top();
    pq.pop();
    auto b = pq.top();
    pq.pop();

    int s = a.cost + b.cost;
    result += s;
    pq.push({ s });
}

int main() {

	//freopen("sample.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        pq.push({temp });
	}

    while (pq.size() > 1) {
        solve();
    }

    cout << result;

	return 0;
}