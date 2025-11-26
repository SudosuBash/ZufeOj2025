#include <bits/stdc++.h>
using namespace std;

int dp[1001] = {0};
//dp[w] = v w为重量 v为价值
int weight[1001] = {0};
int main() {
    int W,n;
    cin >> n >> W;
    for(int i=1;i<=n;i++) {
        cin >> weight[i];
    }

    for(int i=1;i<=n;i++) { //i:物品
        for(int j=W;j>=1;j--) { //j:价值
            if(j >= weight[i]) 
                dp[j] = max(dp[j],dp[j-weight[i]]  + weight[i]);
        }
    }
    cout << dp[W] << endl;
    return 0;
}