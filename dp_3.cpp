#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001] = {0};
//dp[n][k] 遍历到n根筷子，有k个人，总每双筷子的平方差之和为多少?
int kuaiziLeng[1001] = {0};
int main() {
    int N,K;
    cin >> N >> K;
    for(int i=1;i<=N;i++) {
        cin >> kuaiziLeng[i];
    }
    sort(kuaiziLeng+1,kuaiziLeng+N+1);
    
    return 0;
}