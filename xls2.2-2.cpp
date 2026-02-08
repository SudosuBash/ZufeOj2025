#include <bits/stdc++.h>
using namespace std;

int res = 0;
void dfs(int index,int value,int target) {
    if(value == target) {
        res+=1;
        return;
    }
    if(value > target) return;
    dfs(index+1,value+index*index,target);
    dfs(index,value+index*index,target);
}
int main() {
    int n;
    cin >> n;
    dfs(1,0,n);
    cout << res << endl;
    return 0;
}