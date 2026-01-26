#include <bits/stdc++.h>
using namespace std;

/**
 * dp计数问题
 */
int dp[110][110][110] = {0};

//dp[i][j][k]: 
/**
 * i: 遇到前i次店
 * j: 遇到前j次花
 * k: 还剩余多少酒
 * dp[i][j][k]: 数量
 */
void solv(int N,int M) {
    dp[0][0][2] = 1; // 剩余2L酒的时候，计数1种
    for(int i=0;i<=N;i++) { //前i次店
        for(int j=0;j<=M;j++) { //前i次花
            for(int k=0;k<=M;k++) { //酒量
                if(i == 0 && j == 0) {
                    continue; //跳过
                }
                if(i >= 1 && k % 2 == 0) {
                    dp[i][j][k] += dp[i-1][j][k/2]; //上一个店是酒店
                }
                if(j>=1) {
                    dp[i][j][k] += dp[i][j-1][k+1]; //上一个店是花店
                }
                dp[i][j][k] %= 1000000007; //mod
            }
        }
    }
    /**
     * Q: 为什么是 dp[N][M-1][1] ?
     * 我们知道,dp[N][M][0]的状态对应酒量为0, 逛过N个酒店和M个花店
     * 但是最后一个到底是花店还是酒店呢?我们并不知道
     * 但是根据递推式dp[N][M][0] = dp[N-1][M][0] + dp[N][M-1][1]，可以知道:
     *      dp[N-1][M][0]对应最后一个店是酒店，此时此刻没有酒了的情况
     *      dp[N][M-1][1]对应最后一个店是花店，此时此刻还有一斗酒的情况
     * 我们只需要后者，所以这个算式填写 dp[N][M-1][1]
     */
    cout << dp[N][M-1][1];
}
int main() {
    int N,M;
    cin >> N >> M;
    solv(N,M);
    return 0;
}