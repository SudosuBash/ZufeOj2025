#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string strArrs[1000001];
int energy[1000001];

int dp[3][1000001]; 
//dp[i][j]: 反转能量
//i: 翻转/不翻转
//j: 第j个字符串
int main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> energy[i];
    }
    for(int i=1;i<=n;i++) {
        cin >> strArrs[i];
    }

    for(int i=1;i<=2;i++) {
        for(int j=2;j<=1000;j++) {
            dp[i][j] = 2147483647; //初始化最大值
        }
    }
    dp[1][1] = energy[1];//初始化
    // dp[1][1] = dp[2][1] = 0
    for(int i=2;i<=n;i++) { //第i个字符串
        string nowS1 = strArrs[i];
        reverse(nowS1.begin(),nowS1.end());

        string prevS1 = strArrs[i-1];
        reverse(prevS1.begin(),prevS1.end());
        if(strArrs[i] >= strArrs[i-1]) {
            dp[2][i] = min(dp[2][i],dp[2][i-1]);
        }
        if(strArrs[i] >= prevS1) {
            dp[2][i] = min(dp[2][i],dp[1][i-1]);
        }

        if(nowS1 >= strArrs[i-1]) {
            dp[1][i] = min(dp[1][i],dp[2][i-1] + energy[i]);
        }
        if(nowS1 >= prevS1) {
            dp[1][i] = min(dp[1][i],dp[1][i-1] + energy[i]);
        }
    }
    int cmin = min(dp[1][n],dp[2][n]);
    if(cmin == 2147483647) cmin = -1;
    cout << cmin << endl;
    return 0;
}