#define _CRT_SERCURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int N, M;
int parent[1000001];

int find(int x) {

	if (x == parent[x]) return x; // 본인이 대표 노드이면 바로 리턴

	parent[x] = find(parent[x]); //본인이 대표 노드가 아니면 다시 찾으러감
		                         //대표 노드를 찾으면 그 대표노드 값을 저장

	return parent[x]; //자신이 저장한 대표노드 값을 리던해서 자신을 부른 노드에 전달
}

void setunion(int x, int y) {
	x = find(x); // 대표노드 찾으러가기
	y = find(y);

	if (x == y) return; //두개의 대표노드가 같다면 리턴
	parent[y] = x; // 두개의 대표노드가 다르다면 합쳐줘야하기에 값입력
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	//부모 배열 초기화
	for (int i = 0; i <= N; i++){
		parent[i] = i;
	}

	for (int i = 0; i < M; i++){
		int o, a, b;
		cin >> o >> a >> b;

		if (o == 0) {//union하기
			setunion(a, b);
		}
		else {//같은 집합인지 확인
			if (find(a) == find(b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}

	return 0;
}