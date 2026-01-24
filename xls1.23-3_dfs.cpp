#include <bits/stdc++.h>
using namespace std;

int dp[101][100001] = {0};
int weight[101] = {0};
int main() {
    int N;
    cin >> N;
    int w = 0;
    for(int i=1;i<=N;i++) {
        cin >> weight[i];
        w+=weight[i];
    }
    sort(weight,weight+N);
    dp[1][weight[1]] = 1;
    for(int i=2;i<=N;i++) {
        for(int j=1;j<=w;j++) {
            dp[i][weight[i]] = 1;
            if(dp[i-1][j] == 1) {
                dp[i][j] = dp[i-1][j];
                dp[i][j+weight[i]] = 1;
                dp[i][abs(j-weight[i])] = 1;
            }
        }
    }
    int c = 0;
    for(int j=1;j<=w;j++) {
        c+=dp[N][j];
    }
    cout << c << endl;
    return 0;
}