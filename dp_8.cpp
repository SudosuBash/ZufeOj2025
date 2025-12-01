/**
 * 跳房子
 */
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAX_SIZE 1000001
#define MAX_DISTANCE 1000001

long long solv8_distance[MAX_SIZE];
long long score[MAX_SIZE];

long long dp[MAX_DISTANCE];
//dis: 机器人跳的固定距离
long long solve(long long golden,int maxN,long long dis,long long k) {
    memset(dp,0x80,MAX_DISTANCE * sizeof(long long)); //init
    //0x80808080是一个很小的数字
    dp[0] = 0; //第0个格子肯定最多只能是0了
    for(int i=1;i<=maxN;i++) {
        long long currentDis = solv8_distance[i];
        long long furthest = dis + golden;
        long long nearest = max(0ll,dis - golden);
        for(int j=i-1;j>=0;j--) {
            long long prevDis = solv8_distance[j];
            // 这个条件其实可以忽略了，因为上面定义了很小的数字
            // if(prevDis < nearest) break; //跳不到
            if(currentDis - prevDis > furthest) break;
            if(currentDis - prevDis < nearest) continue;
            dp[i] = max(dp[i],dp[j] + score[j]);
            if(dp[i] >= k) return golden;
        }
        // for(int j = nearest;j<=furthest;j++) {
        //     if(currentDis-j<0) 
        //         break;
        //     dp[currentDis] = max(dp[currentDis],dp[currentDis - j] + score[currentDis-j]);
        //     if(dp[currentDis] >= k) return golden; 
        // }
    }
    return 0ll;
}
int main() {
    int n,d;
    long long k;
    cin >> n >> d >> k;
    for(int i=1;i<=n;i++) {
        cin >> solv8_distance[i];
        cin >> score[i];
    }
    long long minGold = -1;
    long long maxGolden = 2000;
    long long l=0,r=maxGolden;
    while(l<=r) {
        long long mGold = (0l+r) / 2;
        if(!solve(mGold,n,d,k)) {
            l = mGold + 1;
        } else {
            minGold = mGold;
            r = mGold - 1;
        }
    }
    cout << minGold;
    return 0;
}