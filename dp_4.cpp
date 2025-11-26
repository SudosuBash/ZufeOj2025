#include <bits/stdc++.h>
using namespace std;

int dp[101][101] = {0};
int dis[1001] = {0};
int prevDis[1001] = {0};
int main() {
	int N,M,K;
	//N集会点 M个警察 1警察管K个集会点
	cin >> N >> M >> K;
	for(int i=1;i<=N;i++) {
		cin >> dis[i];
		prevDis[i] = prevDis[i-1] + dis[i];
	}
	//dp[i][j]: 第i个集会点,有j个警察.管理dp[i][j]个人
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {	
			if(i <= K*j) dp[i][j] = dp[i-1][j] + dis[i];
			else {
				dp[i][j] = max(dp[i-K][j-1] + prevDis[i] - prevDis[i-K],dp[i-1][j]);
				// dp[i][j]不能全覆盖的话,dp[i-K][j-1]照样不能全覆盖的
				// 最后递推到初始条件 dp[i-jK][0] .
				//max(dp[i-K][j-1] + prevDis[i] - prevDis[i-K],dp[i-1][j]) 代表选择/不选该摊位，选择的话就肯定选择后面K个集会点了
				// dp[i-jK][0]就是0,所以最后递推到"前j个和
				printf("dp[%d][%d] = max(dp[%d][%d] + prevDis[%d] - prevDis[%d],dp[%d][%d])\n",i,j,i-K,j-1,i,i-K,i-1,j);
			}
		}
	}
	cout << dp[N][M];
	return 0;
}