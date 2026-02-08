#include <bits/stdc++.h>
using namespace std;

int dp[101][2] = {0};
char str[100001] = {0};
//前i个字符,第i个字符翻转后最少的次数
//0:未反转 1:反转
int main() {
    int c;
    cin >> c;
    for(int i=1;i<=c;i++) {
        cin >> str[i];
    }
    dp[1][1] = 1;
    for(int i=2;i<=c;i++) {
        int s = str[i] - '0';
        int lst = str[i-1] - '0';
        if(s == 1) {
            if(lst == 0) {
                dp[i][0] = dp[i-1][0]; 
                dp[i][1] = dp[i-1][1] + 1;
            } else {
                dp[i][0] = dp[i-1][1];
                dp[i][1] = dp[i-1][0] + 1;
            }
        } else {
            if(lst == 0) {
                dp[i][0] = dp[i-1][1]; 
                dp[i][1] = dp[i-1][0] + 1;
            } else {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1] + 1;
            }
        }
    }
    return 0;
}