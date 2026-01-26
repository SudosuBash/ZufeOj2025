#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int u;
    int v;
    int value;
} obj_t;

priority_queue<obj_t> obj;

int collection[1001] = {0};
bool operator<(const obj_t& o1,const obj_t& o2) {
    return o1.value > o2.value;
}

int find(int x) {
    if(collection[x] == x) {
        return x;
    }
    collection[x] = find(collection[x]);
    return collection[x];
}
int main() {
    int n,k;
    cin >> n >> k;

    int csum = 0;
    for(int i=0;i<k;i++) {
        int u,v,val;
        cin >> u >> v >> val;
        obj_t o = {.u = u,.v = v,.value = val};
        obj.push(o);
        csum += val;
    }

    for(int i=1;i<=n;i++) {
        collection[i] = i;
    }
    int proc = 0;
    int procsum = 0;
    while(proc < n-1 && !obj.empty()) {
        obj_t o = obj.top();
        obj.pop();
        
        int rootX = find(o.u);
        int rootY = find(o.v);
        if(rootX == rootY) continue;
        collection[rootY] = rootX; //连通
        procsum += o.value;
        proc++;
    }
    cout << csum - procsum << endl;
    return 0;
}