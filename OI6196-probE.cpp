#include <bits/stdc++.h>
using namespace std;

int collection[20002] = {0};
int find(int x) {
    int v = x;
    while(collection[x] != x) {
        x = collection[x];
    }
    collection[v] = x;
    // return collection[v] 
    return x;
}
int main() {
    // freopen("6196e_in.txt","r",stdin);
    // freopen("6196e_")
    int N,M;
    cin >> N >> M;
    for(int i=1;i<=N;i++) {
        collection[i] = i;
    }
    for(int i=1;i<=M;i++) {
        int ci,di;
        scanf("%d%d",&ci,&di);
        // cin >> ci >> di;
        int u = find(ci);
        int v = find(di);
        if(u!=v) collection[v] = u;
    }
    int Q;
    cin >> Q;
    for(int i=0;i<Q;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        // cin >> u >> v;
        printf("%s\n",(find(u) == find(v) ? "Yes" : "No"));
    }
    return 0;
}