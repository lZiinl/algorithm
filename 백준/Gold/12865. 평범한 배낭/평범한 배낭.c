#include<stdio.h>
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

int N, K;

struct Item{
	int w, v;
};

struct Item bag[101];

int dp[100001][101];

int main() {

	scanf("%d%d", &N, &K);

	for (int i = 1; i <= N; i++){
		scanf("%d%d", &bag[i].w, &bag[i].v);
	}

	for (int i = 1; i <= K; i++){
		for (int j = 1; j <= N; j++){

			if (bag[j].w > i) {
				dp[i][j] = dp[i][j-1];
			}
			else {
				dp[i][j] = MAX(dp[i - bag[j].w][j-1] + bag[j].v, dp[i][j-1]);
			}

		}
	}

	printf("%d", dp[K][N]);

	return 0;
}