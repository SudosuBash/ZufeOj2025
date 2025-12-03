#include <iostream>
#include <vector>
using namespace std;

typedef long long i64;
i64 candies[10001];
i64 dp[101][101];
//dp[i][j]: 
// i: 糖果数量%k的余数
// j: 当前遍历到第j个糖果品类了
// dp[i][j]: 可以获得的最大的糖果数量
int main() {
    int N,K;
    cin >> N >> K;
    for(int i=1;i<=N;i++) {
        cin >> candies[i];
    }

    for(int i=1;i<=N;i++) {
        for(int j=0;j<K;j++) {
            dp[j][i] = max(dp[j][i],dp[j][i-1]);
            //这部分是不选糖果(准确的说不能选），这时候需要继承上一个状态，该状态和上一个状态一样
            //j=[0..K]的时候有可能
            i64 selected = candies[i] + dp[j][i-1];
            int index = selected % K;
            dp[index][i] = max(dp[index][i],selected);
            //这部分是选了糖果，但是从第i-1袋所有的不同余数的糖果那选
            //最终测算结果保存到对应余数的包装里面，取最大保证最优
            //每次决策都取最大，确保值最大
        }
    }

    int res = 0;
    for(int i=N;i>=1;i--) {
        res = dp[0][i];
        if(res != 0) break;
    }
    cout << res << endl;
    return 0;
}