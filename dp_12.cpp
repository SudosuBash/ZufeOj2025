#include <iostream>
#include <vector>
using namespace std;

unsigned long long dp[10001] = {0};
int nall[21] = {0};
int main() {
    int n,m;
    cin >> n >> m; //n:货币 m:求的货币
    for(int i=1;i<=n;i++) {
        cin >> nall[i];
    }
    dp[0] = 1; //如果取到0了，代表货币本身是可以被算进去的，所以dp[0]=1

    //修正后的代码(老师写的，我改了一下)
    //求组合数
    //先遍历所有的货币面额，再遍历所有情况
    //由于每次面额都是固定的，那么也就是说每次dp[i]存储的都是从1加到i的方案总数
    //所以dp[i]永远是sum(nall[1..i])的遍历顺序(先加nall[1]，再加nall[2]，...)，是不会出现"排列数"的情况的
    for(int i=1;i<=n;i++) { //遍历所有的货币总数
        for(int j=1;j<=m;j++) { //遍历所有最终的货币数量
            if(j-nall[i] >= 0) {
                dp[j] += dp[j-nall[i]];
            }
        }
    }

    //求排列数，这是我第一次写的代码
    //这种会发生什么情况呢?
    //dp[i-nall[j]]+dp[i]实际上是所有排列数，例如dp[i-nall[j]]包含了1+2,dp[i]为1，但是另外一种情况是dp[i-nall[j]]包含了1+1，而dp[i]为2
    //这样直接导致排列数重复，导致结果全错
    // for(int i=1;i<=m;i++) { //遍历所有最终的货币数量
    //     for(int j=1;j<=n;j++) { //遍历所有货币总数
    //         if(i - nall[j] >= 0) {
    //             dp[i] += dp[i-nall[j]];
    //         }
    //     }
    // }
    cout << dp[m];
    return 0;
}