#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001] = {0};
//dp[i][j] 跳到第i个格子 花费j个金币 获得dp[i][j]个积分
int gezi[1001] = {0};
//格子积分
int main() {
    int n,d,k;
    cin >> n >> d >> k;
    for(int i=1;i<=n;i++) {
        int a1;
        int a2;
        cin >> a1 >> a2;
        gezi[a1] = a2;
    }
    int index = -1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=2000;j++) {
            int tmp1 = 0;
            for(int g=0;g<i;g++) { //跳到这儿之前，花费了多少金币
                int distance = g + d;
                if(d < g) continue;
                //i + d - g = nowI
                //i = nowI - d + g
                int disg = i - d +g; //原来的距离
                if(disg < 0) continue;
                tmp1 = max(dp[disg][j-g],tmp1);
                //最大的分数
            }
            dp[i][j] = tmp1 + gezi[i];
            if(dp[i][j] >= k) index = min(index,j);
        }
    }
    cout << index << endl;
    return 0;
}