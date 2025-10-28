/**
 * Leetcode 51
* ACWing 843 - n皇后
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int qipan[10][10] = {0};
int row[10] = {0};
int diag1[20] = {0};
int diag2[20] = {0};
int method = 0;

int couldBePut(int i,int j) {
    int l=i,r=j;
    if (row[j] == 1) return 0;
    while (l>=0 && r>=0) {
        if (qipan[l][r]) return 0;
        l--;
        r--;
    }
    l=i,r=j;
    while (l>=0 && r<n) {
        if (qipan[l][r]) return 0;
        l--;
        r++;
    }
    l=i,r=j;
    while (l<n && r>=0) {
        if (qipan[l][r]) return 0;
        l++;
        r--;
    }
    return 1;
}
void dfs(string putStr,int res,int currentColumn) {
    if (res == n) {
        cout << putStr;
        cout << endl;
        method += 1;
        return;
    }
    for (int j=0;j<n;j++) {
        if (qipan[currentColumn][j]== 0 && couldBePut(currentColumn,j)) {
            int c = 1;
            qipan[currentColumn][j] = 1;
            row[j] = 1;
            dfs(putStr + to_string(j+1)+" ",res+c,currentColumn+1);
            qipan[currentColumn][j] = 0;
            row[j] = 0;
        }
    }
}
int main() {
    cin >> n;
    //n < 10
    dfs("",0,0);
    cout << method;
    return 0;
}