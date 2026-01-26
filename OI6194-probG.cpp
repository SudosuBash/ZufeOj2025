#include <bits/stdc++.h>
using namespace std;

vector<int> in[51];
int used[51] = {0};
void dfs(int n,int index) {
    cout << index-1 << " ";
    used[index] = 1;
    for(int j=0;j<in[index].size();j++) {
        if(!used[in[index][j]]) {
            dfs(n,in[index][j]);
        }
    }

}
int main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        in[i].clear();
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int num;
            cin >> num;
            if(num == 1) {
                in[i].push_back(j);
            }
        }
    }
    dfs(n,1);
    return 0;
}