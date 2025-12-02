#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int weight[10000001];
int dp[10000001];
int main() {
    int n,c;
    cin >> n >> c;
    for(int i=1;i<=n;i++) {
        cin >> weight[i];
    }
    for(int i=1;i<=n;i++) {
        //for(int j=1;j<=c;j++) : 完全背包
        for(int j=c;j>0;j--) { // 01背包
            if(j-weight[i] >= 0) {
                dp[j] = max(dp[j],dp[j-weight[i]] + weight[i]);
            }
        }
    }

    cout << dp[c] << endl;
    return 0;
}