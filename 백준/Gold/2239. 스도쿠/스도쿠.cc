#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int zero_cnt;
char map[9][9];
int flag;

void input() {
    for (int i = 0; i < 9; i++){
        cin >> map[i];
    }

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (map[i][j] == '0') zero_cnt++;
        }
    }
}

bool check(int y, int x, char c) {

    for (int i = 0; i < 9; i++){
        if (map[y][i] == c)
            return false;
    }

    for (int i = 0; i < 9; i++) {
        if (map[i][x] == c)
            return false;
    }

    int section_x = x / 3 * 3, section_y = y / 3 * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (map[section_y + i][section_x + j] == c) return false;
        }
    }

    return true;
}

void solve( int level) {
    
    if (level == zero_cnt) {
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                cout << map[i][j];
            }
            cout << "\n";
        }
        flag = 1;
        return;
    }

    for (int i = 0; i < 9 ; i++) {
        for (int j = 0; j < 9 ; j++) {
            if (map[i][j] == '0') {
                for (char k = '1'; k <= '9'; k++) {
                    if (check(i, j, k)) {
                        map[i][j] = k;
                        solve(level + 1);
                        if (flag==1) return;
                        map[i][j] = '0';
                    }
                }
                return; // 빈칸을 찾으면 그 위치에서 모든 숫자를 시도해야 함
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("sample.txt", "r", stdin);

    input();
    solve( 0);

    return 0;
}