#include <bits/stdc++.h>
using namespace std;
//问题关联: dp-12.cpp/面额组合
int dp[801] = {0};
int main() {
    int n;
    cin >> n;
    dp[0] = 1;
    for(int k=0;k<30;k++) {
        for(int i=1;i<=n;i++) {
        
            int s = i - k*k;
            if(s<0) continue;
            dp[i] += dp[s];
        }
    }
    cout << dp[n];
    return 0;
}