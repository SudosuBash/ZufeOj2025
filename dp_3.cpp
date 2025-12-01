#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001] = {0};
//dp[n][k] 遍历到n根筷子，有k个人，总每双筷子的平方差之和为多少?
//dp[n-2][k-1] 第n-2根筷子，第k-1个人
//dp[n][]
int kuaiziLeng[1001] = {0};
int main() {
    int N,K;
    cin >> N >> K;
    for(int i=1;i<=N;i++) {
        cin >> kuaiziLeng[i];
    }
    sort(kuaiziLeng+1,kuaiziLeng+N+1);
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=K+3;j++) {
            if(i < 2 * j) {
                dp[i][j] = 2147483647;//凑不到，直接变成最大值
                continue;
            } 
            //能凑到，选择
            int sig1 = (kuaiziLeng[i] - kuaiziLeng[i-1]) * (kuaiziLeng[i] -kuaiziLeng[i-1]); //长度差4
            dp[i][j] = min(dp[i-2][j-1] + sig1,dp[i-1][j]);
        }
    }
    if(dp[N][K+3] == 2147483647) cout << "-1" << endl;
    else cout << dp[N][K+3];
    return 0;
}