#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int N;
char map[6][6];

struct Node {
    int y, x;
};

vector<Node>teacher;
vector<Node>student;

int flag;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void input() {
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'T') {
                teacher.push_back({ i, j });
            }
            else if (map[i][j] == 'S') {
                student.push_back({ i,j });
            }
        }
    }
}

void check() {
    for (int i = 0; i < teacher.size(); i++){
        Node now = teacher[i];
        
        for (int j = 0; j < 4; j++){
            Node ch = now;
            while (1) {
                ch.x += dx[j];
                ch.y += dy[j];

                if (ch.x < 0 || ch.y < 0 || ch.x >= N || ch.y >= N) break;
                if (map[ch.y][ch.x] == 'T' || map[ch.y][ch.x] == 'O') break;
                if (map[ch.y][ch.x] == 'S') return;

            }
        }
    }
    flag = 1;
}

void solve(int level) {
    
    if (level == 4) {
        check();
        return;
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (map[i][j] != 'X') continue;

            map[i][j] = 'O';
            solve(level + 1);
            if (flag == 1) return;
            map[i][j] = 'X';
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("sample.txt", "r", stdin);

    input();
    solve(1);

    if (flag == 1) {
        cout << "YES";
        return 0;
    }

    cout << "NO";
    return 0;
}