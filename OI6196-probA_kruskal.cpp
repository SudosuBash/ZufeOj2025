/**
 * Kruskal算法
 */
#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int u; //from
    int v; //to
    int val;
} obj_t;

int collection[3003] = {0};
priority_queue<obj_t> obj;

bool operator<(const obj_t& obj1,const obj_t& obj2) {
    return obj1.val > obj2.val;
}

//路径压缩算法
int find(int x) {
    if(collection[x] != x) {
        collection[x] = find(collection[x]); //这个就是路径压缩
    }

    return collection[x];
}


int main() {
    int n,m;
    cin >> n >> m;
    int csum = 0;
    for(int i=1;i<=n;i++) {
        collection[i] = i;
        //孤立节点，自己的父节点为自己
    }
    for(int i=0;i<m;i++) {
        int u,v,val;
        cin >> u >> v >> val;
        obj.push(obj_t{u,v,val});
    }

    int edge = 0;
    while(!obj.empty() && edge < n-1) {
        obj_t front = obj.top();
        obj.pop();
        int lx = find(collection[front.v]);
        int rx = find(collection[front.u]);
        if(lx == rx) continue; //成环了
        collection[lx] = rx; //图根节点更新
        //- 这儿注意不是collection[front.v] = front.u;
        csum += front.val;
        edge ++;
    }
    if(edge != n-1) {
        cout << -1 << endl;
        return 0;
    }
    cout << csum << endl;
    return 0;
}