#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int cur;
    int cost;
} obj_t;
vector<int> graph[100001]; 

int rd[100001] = {0};
int cost_a[100001] = {0};
queue<obj_t> q;

int search(int n) {
    int cost = 0;
    int proced = 0;
    for(int i=1;i<=n;i++) {
        if(rd[i] == 0) {
            q.push(obj_t{i,100});
            proced += 1;
            cost += 100;
        }
    }
    
    while(!q.empty()) {
        obj_t obj = q.front();
        q.pop();

        int cur = obj.cur;
        for(int i=0;i<graph[cur].size();i++) {
            int to = graph[cur][i];
            rd[to] -= 1;
            if(rd[to] == 0) {
                cost += (obj.cost+1);
                proced++;
                cost_a[to] = max(cost_a[to],obj.cost+1);
                //注意: 多个节点需要取最小值.
                q.push(obj_t{to,cost_a[to]});
            }
        }
    }
    if(proced < n) return -1;
    return cost;
}
int main() {
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        graph[b].push_back(a);
        
        rd[a] += 1;
    }
    int s = search(n);
    if(s == -1) {
        cout << "Poor Xed" << endl;
    } else {
        cout << s << endl;
    }
    return 0;
}