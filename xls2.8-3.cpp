#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int qy = 1e9+7;
// int dp[1000001][1001] = {0};
// MLE警告
int limitedLeng = 0;
int n,s,a,b;
ll res = 0;

void dfs(ll sum,int last,int leng) {
    if(leng == n-1) { //加n-1次
        int delta = s - sum;
        int x = delta / n;
        if(x * n == delta) {
            res +=1;
            res%=qy;
        }
        return;
    }
    dfs(sum+last+a,last+a,leng+1);
    dfs(sum+last-b,last-b,leng+1);
}
int main() {
    cin >> n >> s >> a >> b;
    dfs(0,0,0);
    cout << res << endl;
    return 0;
}