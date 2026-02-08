#include <bits/stdc++.h>
using namespace std;

const int cmax = 200002;
vector<int> graph[cmax];
int maxdepths[cmax] = {0};
int collection[cmax] = {0};
int dis[cmax] = {0};
int maxdepth = 0;

int dfs(int x,int step) {
    maxdepth = max(step,maxdepth);
    maxdepths[x] = step;
    for(int i=0;i<graph[x].size();i++) {
        int node = graph[x][i];
        dis[node] = step+1;
        maxdepths[x] = max(maxdepths[x],dfs(node,step+1)); //往后搜索
    }
    return maxdepths[x];
}
int main() {
    int n,x;
    cin >> n >> x;
    for(int i=1;i<n;i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        collection[v] = u;
    }
    dis[1] = 1;
    dfs(1,1);
    int nowheight = dis[x];
    int currentHeight = dis[x]; //当前所在高度
    int subHeight = currentHeight / 2;
    int maxStep = 0; //计算出最大步数

    while(subHeight > 0) {
        maxStep = max(maxdepths[x] - currentHeight,maxStep);
        currentHeight--;
        subHeight --;
        x = collection[x];
    }
    cout << (nowheight - 1 + maxStep) * 2 << endl;
    return 0;
}