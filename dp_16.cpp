//temporary not be solved.
#include <iostream>
#define inf 100000000
using namespace std;
int dp[1001][1001][1001] = {0};
int vec1[1001]; //维度1
int vec2[1001]; //维度2
int vec3[1001]; //维度3
// dp[i][j][k]: 长i宽j,第k个能取到的最高值
int main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> vec1[i] >> vec2[i] >> vec3[i];
    }
    for(int i=1;i<=n;i++) {
        int cmin = inf;

        for(int j=1;j<=n;j++) {
            for(int k=1;k<=i;k++) {

            }
        }
    }
}