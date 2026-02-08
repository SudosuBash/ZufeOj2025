#include <bits/stdc++.h>
using namespace std;

int value[101][101] = {0};
int n,m,k;
int res = 0;
int search[101][101][14][14] = {0};
//记忆化搜索

void dfs(int startX,int startY,int ck,int maxval) {
    //if(startX > n || startY > m)
    if(startX > m || startY > n) return;
    //if(startX == n && startY == m) {
    if(startX == m && startY == n) {
        if(ck == k || (ck == k-1 && value[startY][startX] > maxval)) 
            res = (res+1) % (int)(1e9+7);
        return;
    }
    
    if(maxval < value[startY][startX]) {
        dfs(startX+1,startY,ck+1,value[startY][startX]);
        dfs(startX,startY+1,ck+1,value[startY][startX]);
    }
    dfs(startX+1,startY,ck,maxval);
    dfs(startX,startY+1,ck,maxval);
}
int main() {
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> value[i][j];
        }
    }
    dfs(1,1,0,-1);
    cout << res << endl;
    return 0;
}