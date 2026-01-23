#include <bits/stdc++.h>

using namespace std;

int d[50005] = {0};
int l[50005] = {0},r[50005] = {0};
//l[i]: 截止到i的所获得的最长子序列的长度
//r[i]: 截止到j的所获得的最长子序列的长度(倒过来的)
int main() {
    int N,K;
    cin >> N >> K;
    for(int i=1;i<=N;i++) {
        cin >> d[i];
    }
    sort(d,d+N+1);

    l[1] = 1;
    for(int j=1,i=2;i<=N;i++) {
        while(d[i]-d[j] > K)
            j++;
        l[i] = max(l[i-1],i-j+1);
        //必须要max，记录的是截止到i的最长子序列的长度，而不是i-j子序列的长度
    }

    r[N] = 1;
    for(int j=N,i=N-1;i>=1;i--) {
        while(d[j]-d[i] > K)
            j--;
        r[i] = max(r[i+1],j-i+1);
    }
    int ans = 0;
    for(int i=1;i<=N;i++) {
        // ans=max(ans,l[i]+r[i]);
        ans=max(ans,l[i]+r[i+1]);
        //为什么不是i，而是i+1呢?
        //要搞懂这些，首先问: j-i+1指的是什么?
        //j-i+1指的是子序列的长度(包括i本身)
        //r[i+1]代表包括i+1在内的子序列的最长的长度
        //r[i]代表包括i在内的子序列的最长的长度
        //所以，r[i]+l[i]的话等于i这个长度被计算了2次，答案是错的。
        //eof
    }
    cout << ans << endl;
    return 0;
}