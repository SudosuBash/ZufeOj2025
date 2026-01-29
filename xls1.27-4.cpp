#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int graph[10001][10001] = {0};
int collection[10001] = {0};

int find(int x) {
    int o = x;
    int prev = x;
    int ori_path = 0;
    while(collection[x] != x) {
        prev = x;
        x = collection[x];
        ori_path += graph[prev][x];
        graph[o][x] = ori_path; //累加值
        graph[x][o] = graph[o][x];
        
    }
    collection[o] = x;
    return x;
}

int main() {
    int N,M,Q;
    cin >> N >> M >> Q;
    for(int i=0;i<=10000;i++) {
        collection[i] = i;
    }
    for(int i=0;i<M;i++) {
        int li,ri,Si;
        cin >> li >> ri >> Si;
        li -= 1;
        graph[ri][li] = graph[li][ri] = Si;
        int rx = find(li);
        int ry = find(ri);
        if(rx < ry) {
            collection[ry] = rx;
            graph[rx][ry] = graph[ry][rx] = graph[ri][li] + graph[li][rx] - graph[ri][ry];
        } else if(rx > ry) {
            collection[rx] = ry;
            graph[rx][ry] = graph[ry][rx] = -(graph[ri][li] + graph[li][rx] - graph[ri][ry]);
        }
    }
        

    for(int i=0;i<Q;i++) {
        int l1,l2;
        cin >> l1 >> l2;
        int idx1 =find(l1-1);
        int idx2 = find(l2);
        if(idx1 != idx2) {
            cout << "UNKNOWN" << endl;
            continue;
        }
        cout << graph[l2][l1-1] << endl;
    }
    return 0;
}