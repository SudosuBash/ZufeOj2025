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
    dp[0] = 1;
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=m;j++) {
    //         if(j-nall[i] >= 0) {
    //             dp[j] += dp[j-nall[i]];
    //         }
    //     }
    // }
    for(int i=1;i<=m;i++) { //第i个货币
        for(int j=1;j<=n;j++) { //把每个
            if(i - nall[j] >= 0) {
                dp[i] += dp[i-nall[j]];
            }
        }
    }
    cout << dp[m];
    return 0;
}