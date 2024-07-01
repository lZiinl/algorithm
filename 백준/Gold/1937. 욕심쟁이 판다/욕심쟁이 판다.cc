#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>



typedef long long ll;


using namespace std;
int n;
int board[501][501];
int dp[501][501];


int dfs(int x, int y){
	if(dp[x][y]!=0) return dp[x][y];

	dp[x][y] = 1;
	
	if(x-1>=0 && board[x][y] < board[x-1][y]){
		dp[x][y]= max(dp[x][y], 1+dfs(x-1,y));
	}
	if(x+1<n && board[x][y] < board[x+1][y]){
		dp[x][y]= max(dp[x][y], 1+dfs(x+1,y));
	}
	if(y-1>=0 && board[x][y] < board[x][y-1]){
		dp[x][y]= max(dp[x][y], 1+dfs(x,y-1));
	}
	if(y+1<n && board[x][y] < board[x][y+1]){
		dp[x][y]= max(dp[x][y], 1+dfs(x,y+1));
	}

	return dp[x][y];

}

int main(int argc, char** argv)
{	

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> board[i][j];

	int m = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++){
			m = max(m, dfs(i,j));
		}
	
	cout << m;
	
}