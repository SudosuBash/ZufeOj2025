#include <bits/stdc++.h>
using namespace std;

int price[110][110];
int dp[10001] = {0};
//dp[i][j] 表示第i天拥有j枚金币
//p[i][j]表示第 i 天第 j 种纪念品的价格。 
int main() {
    int T,N,M;
    /**
     * 第一行包含三个正整数 T, N, M，相邻两数之间以一个空格分开，
     * 分别代表未来天数T，纪念品数量 N，小伟现在拥有的金币数量 M。 
     * 接下来 T 行，每行包含 N 个正整数，相邻两数之间以一个空格分隔。
     * 第 i 行的N 个正整数分别为 Pi,1,Pi,2,……,Pi,N
     * 其中 P_{i,j} 表示第 i 天第 j 种纪念品的价格。 
     */
    cin >> T >> N >> M;
    for(int i=1;i<=T;i++) {
        for(int j=1;j<=N;j++) {
            cin >> price[i][j];
        }
    }
    for(int i=1;i<T;i++) {
        int plg[110] = {0}; //差价
        for(int j=1;j<=N;j++) {
            plg[j] = max(price[i+1][j] - price[i][j],0);
        }
        memset(dp,0,sizeof(dp));
        //dp[j][k] j:商品种类 k:价格
        for(int j=1;j<=N;j++) {
            for(int k=0;k<=M;k++) {
                if(k - price[i][j] >= 0) { //价格可以买到
                    dp[k] = max(dp[k-price[i][j]] + plg[j],dp[k]);
                }
            }
        }
        
        M+=dp[M];
    }

    

    cout << M << endl;
    return 0;
}