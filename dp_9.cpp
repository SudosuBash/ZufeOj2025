#include <iostream>
#include <vector>
using namespace std;

int color[100001];
int cost[1001][1001];

int dp[1001][1001];
//dp[i][j]: 第 i 棵树，颜值多少 j，耗费油漆dp[i][j]

//状态：
// 几棵树 n，几种颜色 m，颜值多少 k，耗费油漆多少
//n: 几棵树?
//m: 几种颜色?
void solv(int n,int m) {
    int currentYanzhi = 0;
    for(int i=1;i<1001;i++) {
        for(int j=1;j<1001;j++) {
            dp[i][j] = 2147483647;
        }
    }
    for(int i=1;i<=n;i++) { //树i
        if(color[i]!=0) { //当前已经上色，可以忽略了
            if(color[i] == color[i-1]) dp[i][currentYanzhi] = dp[i-1][currentYanzhi]; //继承上个状态 
            else {
                currentYanzhi += 1;
                dp[i][currentYanzhi] = dp[i-1][currentYanzhi - 1];
            }
        } else {
            int tmp2 = currentYanzhi;
            for(int j=1;j<=m;j++) { //颜色j
                int tmp1;
                if(j == color[i-1]) tmp1 = dp[i-1][currentYanzhi];
                else {
                    currentYanzhi +=1;
                    tmp1 = dp[i-1][currentYanzhi - 1];
                }
                dp[i][currentYanzhi] = min(dp[i][currentYanzhi],tmp1 + cost[i][j]);
                currentYanzhi = tmp2;
            }

        }
    }
}
int main() {
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) {
        cin >> color[i];
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> cost[i][j];
        }
    }
    solv(n,m);
    int maxYouqi = 2000;
    int l=0,r=maxYouqi;
    while(l<=r) {
        
    }
    return 0;
}