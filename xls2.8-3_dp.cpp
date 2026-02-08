#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int fjx = 25;
const int qy = 1e9+7;
int dp[1001][fjx*2+1] = {0};
// MLE警告
int limitedLeng = 0;
int n,s,a,b;

int main() {
    cin >> n >> s >> a >> b;
    dp[1][fjx+a] = 1;
    dp[1][fjx-b] = 1;
    for(int i=2;i<=n-1;i++) {
        for(int j=0;j<fjx*2+1;j++) {
            int sum = j - fjx;
            
            if(j+j-a >= 0) 
                dp[i][j] = ((dp[i-1][j-a]) + dp[i][j]) % qy;
            if(j+b < fjx*2+1)
                dp[i][j] = ((dp[i-1][j+b]) + dp[i][j]) % qy;
        }
    }
    int res = 0;
    for(int i=0;i<=fjx*2;i++) {
        if(dp[n-1][i]) {
            int c = i - fjx;
            if((s - c) % n == 0) {
                res += dp[n-1][i];
                res %= qy;
            }
        }
    }
    cout << res << endl;
    return 0;
}