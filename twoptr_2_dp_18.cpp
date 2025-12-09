#include "bits/stdc++.h"

using namespace std;

char str[100001];
int dp[100001];
int main() {
    
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++) {
        cin >> str[i];
    }
    for(int i=1;i<=n;i++) {
        int j;
        for(j=i-1;j>0;j--) {
            if(str[i] == str[j]) break;
        }
        dp[i] = dp[j] + 1;
    }
    
    return 0;
}