#include<bits/stdc++.h>
using namespace std;

const int index_max = 100001;
const int yhq_price = 180; //优惠券的价格
const int yhq_yz = 280; //优惠券的阈值
typedef struct {
    int price;
    int option;
    int necessary;
    int with_necessary;
} goods;

goods g[index_max];

int dp[10001][10001][2][2] = {0};
/**
 * dp[i][j][k][l]: 
 *  i: 第i个商品
 *  j: price
 *  k: 是否选择凑单商品?
 *  l: 是否叠加优惠券?
 *  dp[i][j]: option
 * 
 * */
int main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> g[i].price >> g[i].option >> g[i].necessary >> g[i].with_necessary;
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=index_max;j++) {
            if(j - g[i].price >= 0) {
                if(g[i].necessary) {
                    dp[i][j][1][0] = min(dp[i-1][j-g[i].price][0][0],dp[i-1][j-g[i].price][1][0]) + g[i].price;
                    dp[i][j][0][0] = dp[i-1][j][0][0]; //继承上一状态
                } else {
                    if(g[i].with_necessary) {
                        dp[i][j][0][0] = dp[i-1][j-g[i].price][0][0];
                    }
                    dp[i][j][1][0] = dp[i-1][j][1][0];
                    //dp[i][j][0][0] = min(dp[i-1][j-g[i].price][0][0],dp[i];
                }

                if(dp[i][j][1][0])
            }

            
        }
    }
}