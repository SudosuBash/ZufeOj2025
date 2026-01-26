#include <bits/stdc++.h>
using namespace std;
#define inf 0x3e3e3e3e
int graph[1001][1001] = {0};
int cost[1001] = {0};
int used[1001] = {0};

int prim(int n) {
    used[1] = 1; //第一个节点添加到集合U
    for(int i=1;i<=n;i++) {
        cost[i] = graph[1][i];
    }
    int val = 0; //求和
    int cnt = 1; //处理个数
    while(cnt < n) {
        int mint = inf;
        int next_add_to_v = -1;
        for(int i=1;i<=n;i++) {
            if(!used[i] && mint > cost[i]) { //在集合V,找最小连接点
                next_add_to_v = i;
                mint = cost[i];
            }
        }

        if(mint == inf) {
            return -1; //找不到了    
        }

        val += mint;
        used[next_add_to_v] = 1;//加入集合U
        for(int i=1;i<=n;i++) {
            if(!used[i] && cost[i] > graph[i][next_add_to_v]) {
                cost[i] = graph[i][next_add_to_v];
            }
        }
        cnt++;
    } 
    return val;
}
int main() {
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i == j) graph[i][j] = 0;
            else graph[i][j] = inf;
        }
    }
    for(int i=0;i<m;i++) {
        int u,v,val;
        cin >> u >> v >> val;
        graph[u][v] = graph[v][u] = val;
    }

    cout << prim(n) << endl;
    return 0;
}