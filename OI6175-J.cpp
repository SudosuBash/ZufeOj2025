#include <bits/stdc++.h>
using namespace std;

int dp[101][101];
int s[10001];
int main() {
    int N;
    cin >> N;
    for(int i=1;i<=N;i++) {
        int n;
        cin>>n;
        s[i] = s[i-1] + n;
        dp[i][i] = 0;
    }
    for()
    return 0;
}