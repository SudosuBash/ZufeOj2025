//土拨鼠吃花
#include <iostream>
using namespace std;
#define FLOWER 100000
long long dp[FLOWER+1];
//本质:
//dp[i]: 第i朵花的方案数
//选红色: dp[i] += dp[i-1],前i-1个方案数就是第i个的方案数
//选白色: i到i-k+1只能是白花，要不然不是合法的结果
//  所以这种情况的方案数为 dp[i-k],前i-k个的方案数就是第i个的方案数
//  所以就是 dp[i] += dp[i-k]
//联系题目: 
// 1.曙曙献爱心(dp) (思路最接近)
// 2.筷子(dp)
// 3.币种数量(dp)
int main() {
    int t,k;
    cin >> t >> k;
    dp[0] = 1; //总共吃0朵花的时候，什么都不吃也是一种方案
    for(int i=1;i<=FLOWER;i++) {
        if(i-k >= 0) {
            dp[i] += dp[i-k];
        }
        dp[i] += dp[i-1];
        dp[i] %= 1000000007;
    }
    for(int i=1;i<=FLOWER;i++) {
        dp[i] += dp[i-1]; //前缀和加速
        dp[i] %= 1000000007;
    }
    for(int i=0;i<t;i++) {
        int l,r;
        cin >> l >> r;
        cout << (dp[r] - dp[l-1] + 1000000007) % 1000000007 << endl;
        //数学的锅，死这儿，mod公式是(x+y) % y不是x%y
        //因为r很大的时候，dp[r]是取mod后的结果，是完全有可能小于dp[l]的
        //取模公式发力了
    }
    
    return 0;
}   