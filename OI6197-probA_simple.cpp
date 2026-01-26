/**
 * Dijkstra算法
 */
#include <bits/stdc++.h>
using namespace std;
#define inf 0x3e3e3e3e
int proc[1001] = {0};
//proc是走过的路径
int min_val[1001] = {0};
//min_val是最小价值
int graph[1001][1001] = {0};
int dijkstra(int start,int end,int point) {
    
    proc[start] = 1;
    int min_index = -1, cmin_val = inf;
    for(int i=0;i<point;i++) {
        if(!proc[i]) {
            min_val[i] = min(min_val[i], graph[start][i] + min_val[start]);
            if(min_val[i] < cmin_val) {
                cmin_val = min_val[i];
                min_index = i;
            }
        }
    }
    if(min_index != -1) {
        return dijkstra(min_index,end,point);
    } else {
        return min_val[end];
    }
}
int main() {
    memset(min_val,0x3e,sizeof(min_val));
    min_val[0] = 0;
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            graph[i][j] = inf;
        }
    }
    for(int i=0;i<m;i++) {
        int u,v,val;
        cin >> u >> v >> val;
        graph[u][v] = val;
    }
    int end;
    cin >> end;
    cout << dijkstra(0,end,n) << endl;
    return 0;
}