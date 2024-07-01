#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring>
#include <cmath>
#include <set>
#include <queue>
#include <unordered_map>
#include <deque>
#include <string>

typedef long long ll;

using namespace std;



using namespace std;
int n;
int map[101][101];
int colo[101][101];
int ans[2];
int leftd[101]; //왼->오 방향 대각선
int rightd[101]; // 오->왼 방향 대각선


void dfs(int now, int depth, int color){
	
	for(int i=now; i<=n*n; i++){
		int row = (i%n == 0)? i/n : i/n + 1;
		int col = (i%n == 0)? n : i%n;
		if(colo[row][col] != color) continue;
		if(map[row][col] == 1 && leftd[col-row +n]==0 && rightd[col+row-1] ==0){
			leftd[col-row +n] = 1;
			rightd[col+row-1] =1;
			dfs(i+1, depth+1, color);
			leftd[col-row +n] = 0;
			rightd[col+row-1] =0;
		}
	}

	if(ans[color] < depth){
		ans[color] = depth;
	}
	
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
   
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++){
			cin >> map[i][j];	
			if(i%2 ==0 && j%2 ==0){
				colo[i][j] = 1;
			}
			if(i%2 == 1 && j%2 ==1){
				colo[i][j] = 1;
			}
		}
	
	dfs(1,0,1);
	dfs(1,0,0);
   
	cout << ans[0] + ans[1];
}