#include <bits/stdc++.h>
using namespace std;
int weight[31];

int dp[100001];
//此问题本质求的是在x/2内最大的数据
int main() {
    
    int n;
    while(cin >> n) {
        int csum = 0;
        for(int i=1;i<=n;i++) {
            cin >> weight[i];
            csum += weight[i];
        }
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=n;i++) {
            for(int j=csum/2; j>0; j--) {
                if(j-weight[i] >= 0) 
                    dp[j] = max(dp[j],dp[j-weight[i]] + weight[i]);            
            }
        }
        cout << (csum) - 2*dp[csum/2] << endl;
    }

    return 0;
}