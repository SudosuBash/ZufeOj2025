#include <bits/stdc++.h>
using namespace std;

#define inf 0x3e3e3e3e
int graph[1001][1001] = {0};
int cost[1001] = {0};
int uv[1001] = {0};

int prim(int n) {
    uv[1] = 1; //第一个元素加入U

    for(int i=1;i<=n;i++) {
        cost[i] = graph[1][i];
    }
    int rmin = 0;
    int cnt = 1;
    while(cnt < n) {
        int add_to_u = -1, cmin = inf;
        for(int i=1;i<=n;i++) {
            //寻找 V 集合中的最小距离
            if(!uv[i] && cmin > cost[i]) {
                cmin = cost[i];
                add_to_u = i;
            }
        }

        if(cmin == inf) {
            return -1;
        }
        rmin = max(cmin,rmin);
        uv[add_to_u] = 1;
        for(int i=1;i<=n;i++) {
            if(!uv[i] && cost[i] > graph[i][add_to_u]) {
                cost[i] = graph[i][add_to_u];
            }
        }
        cnt++;
    }
    return rmin;
}
int main() {
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i == j) graph[i][j] = 0;
            else graph[i][j] = inf;
        }
    }

    for(int i=0;i<m;i++) {
        int u,v,val;
        cin >> u >> v >> val;
        graph[u][v] = graph[v][u] = val;
    }

    cout << n-1 << prim(n) << endl;
    return 0;
}