#include <bits/stdc++.h>
using namespace std;

int dp[101][101][20] = {0};
int dp2[101][101][20] = {0};
//i: x j: y l: 宝贝数量  dp[i][j][l]: 方案数
//i: x j: y l: 宝贝数量  dp2[i][j][l]: 最大价值
int value[101][101] = {0};
int used[101][101] = {0};
int n,m,k;
int main() {
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> value[i][j];
        }
    }

    dp[1][1][1] = 1;
    dp[1][1][0] = 0;
    dp2[1][1][1] = value[0][0];
    dp2[1][1][0] = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            for(int l=1;l<20;l++) {
                int cur = value[i][j]; //当前价值
                int prv1 = dp2[i-1][j][l-1];
                int prv2 = dp2[i][j-1][l-1];

                if(cur > prv1) {//当前价值比最大价值大
                    dp[i][j][l] += dp[i-1][j][l-1];
                    
                }
                if(cur > prv2) {
                    dp[i][j][l] += dp[i][j-1][l-1];
                }
                dp[i][j][l] += dp[i-1][j][l];
                dp[i][j][l] += dp[i][j-1][l];
                dp2[i][j][l] = max(max(cur,prv1),prv2);
            }
        }
    }
    return 0;
}