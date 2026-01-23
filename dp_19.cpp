#include <bits/stdc++.h>

using namespace std;

int dp[10001]; 
//dp[minute]: 规定时间(minute)之内，能获得的分数
int score[10001];
int minute[10001];
int main() {
    int M,N;
    cin >> M >> N;
    for(int i=1;i<=N;i++) {
        cin >> score[i] >> minute[i];
    }

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(j - minute[i] >= 0) {
                //dp[j]: 我不选这道题目，维持现状(继承上一个)
                //dp[i]:
                // 我选这道题目，在规定的j分钟内，我做这道题目的最大分数
                // = j-minute[i]分钟内我做上一道题的最大分数+当前题目的分数(继承上一个)
                // j-minute[i]分钟内我做上一道题目的最大分数往前递推，一直推到0
                dp[j] = max(dp[j],dp[j-minute[i]] + score[i]);
            }
        }
    }
    cout << dp[M] << endl;
    return 0;
}