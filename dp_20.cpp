// //temporary not be solved.
// #include <bits/stdc++.h>

// using namespace std;

// int dp[101][101];
// //dp[i][j]: 第i种类，第j盆花，总共的方案数
// int limit[101];
// int main() {
//     int n,m;
//     cin >> n >> m;
//     for(int i=1;i<=n;i++) {
//         cin >> limit[i];
//     }
//     dp[0][0] = 1;
//     //种类i花盆0摆放方式为1
//     for(int i=1;i<=n;i++) {
//         //种类i
//         for(int j=0;j<=m;j++) {
//             //花盆j
//             for(int k=0;k<=limit[i];k++) {
//                 if(j-k>=0)
//                     dp[i][j] += dp[i-1][j-k];
//                 //第i种类第j盆花的方案数
//                 // = 种类i-1 第j-k j-k+1 ... j盆花的方案数
//             }
            
//         }
//     }
//     cout << dp[n][m] << endl;
//     return 0;
// }

//dp本质上是数学归纳法
//数学归纳法: 
// 已知P(i)成立
// 假设对 K >= i,P(K)成立
// 推导 P(K) -> P(K+1) 成立
// 又由于P(i)成立，所以P(i+1)成立，进而推出P(i+2)成立，P(K)成立，P(K+1)成立.
//动态规划:
// 已知dp[i] = f(dp[i],dp[n])是全局最优，这个结论成立
// 又已知dp[0](初始状态)成立
// 得到dp[N](目标状态)成立
#include <bits/stdc++.h>

using namespace std;

int dp[101][101];
//dp[i][j]: 第i种类，第j盆花
int limit[101];
int main() {
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        cin >> limit[i];
    }
    for(int i=1;i<=n;i++) {
        dp[i][0] = 1;
    }
    //种类i花盆0摆放方式为1
    dp[0][0] = 1;
    for(int i=1;i<=n;i++) {
        //种类i
        for(int j=1;j<=m;j++) {
            //花盆j
            for(int k=0;k<=limit[i];k++) {
                if(j-k>=0)
                    dp[i][j] += dp[i-1][j-k];
                    dp[i][j] %= 1000007;
                //第i种类第j盆花的方案数
                // = 种类i-1 第j-k j-k+1 ... j盆花的方案数
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}