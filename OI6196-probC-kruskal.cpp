#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int u;
    int v;
    int val;
} obj_t;

int collection[1001] = {0};
priority_queue<obj_t> pq;

bool operator<(const obj_t& o1,const obj_t &o2) {
    return o1.val > o2.val;
}
int find(int x) {
    if(collection[x] == x) {
        return x;
    }
    collection[x] = find(collection[x]);
    return collection[x];
}

int main() {
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;i++) {
        obj_t o;
        cin >> o.u >> o.v >> o.val;
        pq.push(o);
    }
    int proc = 1;
    int cmax = 0;
    for(int i=1;i<=n;i++) {
        collection[i] = i;
    }
    while(!pq.empty() && proc < n) {
        obj_t front = pq.top();
        pq.pop();

        int rootX = find(front.u);
        int rootY = find(front.v);
        if(rootX == rootY) continue;
        collection[rootY] = rootX;
        cmax = max(cmax,front.val);
        proc += 1;
    }
    cout << proc-1 << " " << cmax << endl;
    return 0;
}