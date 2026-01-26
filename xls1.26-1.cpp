#include <bits/stdc++.h>
using namespace std;
/**
 * 理解错题目了qwq...
 */
int tree[100001] = {0};
int min_d = -0x3e3e3e3e;
int res = 1;
//0 1 3 7
void dfs(int n,int limit,int depth) {
    if(n >= limit) return;
    int val = 0;
    for(int i=n;i<min((n*2+1),limit);i++) {
        val += tree[i];
    }
    if(val > min_d) {
        min_d = val;
        res = depth;
    }
    dfs(n*2+1,limit,depth+1);
} 
int main() {
    int n;
    cin >> n;
    memset(tree,0x3e3e,sizeof(tree));
    for(int i=0;i<n;i++) {
        scanf("%d",&tree[i]);
    }
    dfs(0,n,1);
    cout << res << endl;
}