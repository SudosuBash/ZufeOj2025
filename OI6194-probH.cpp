#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
int dfs(int index,int height) {
    int maxc = height;
    for(int i=0;i<graph[index].size(); i++) {
        maxc = max(maxc,dfs(graph[index][i],height+1));
    }
    return maxc;
}
int main() {
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v); //生成一棵树
    }
    cout << dfs(1,1) << endl;
    return 0;
}