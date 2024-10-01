#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int map[101][101];
int N, K, L;
char dat[10001];
int snake[101][101];
int cnt;

void input() {
	cin >> N >> K;

	for (int i = 0; i < K; i++){
		int y, x;
		cin >> y >> x;
		map[y][x] = 1;
	}

	cin >> L;

	for (int i = 0; i < L; i++)
	{
		int S;
		cin >> S;
		char D;
		cin >> D;
		dat[S] = D;
	}
}

// 1 = 오른쪽, 2 = 아래, 3 = 왼쪽 4 = 위

void solve(int y, int x) {
	snake[y][x] = 0;
	int flag = 0;
	int slen = 1;

	while (1) {

		cnt++;

		if (flag == 0) {
			x += 1;
		}
		else if (flag == 1) {
			y += 1;
		}
		else if (flag == 2) {
			x -= 1;
		}
		else if (flag == 3) {
			y -= 1;
		}

		if (map[y][x] == 1) {
			map[y][x] = 0;
			slen++;
		}

		if (snake[y][x] != 0) {
			if ((cnt - snake[y][x]) <= slen) {
				break;
			}
		}

		snake[y][x] = cnt;

		if (y<1 || y>N || x<1 || x>N) {
			break;
		}

		if (dat[cnt] == 'D') {
			flag = (flag + 1) % 4;
		}

		if (dat[cnt] == 'L') {
			flag = (flag + 3) % 4;
		}
	}
}

int main() {
	//freopen("sample.txt", "r", stdin);
	
	input();
	solve(1,1);

	cout << cnt;

	return 0;
}