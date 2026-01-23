#include <bits/stdc++.h>

using namespace std;

//dp[i]: 距离和时间
int dp[100001];
int main() {
    int n,k;
    cin >> n>>k;

    for(int i=0;i<n;i++) {
        dp[i] = 100000000;
    }
    for(int i=n+1;i<=k;i++) {
        if(i-1<0) {
            dp[i] = dp[i%2];
        } else {
            dp[i] = min(dp[i%2],dp[i-1])+1;
        }
    }
    cout << dp[k] << endl;
    return 0;
}