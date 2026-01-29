#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> graph[10001];
vector<int> c[10001];

int graph[101][101] = {0};
ll collection[10001] = {0};

int find(int x) {
    int o = x;
    int prev = x;
    while(collection[x] != x) {
        x = collection[x];
        graph[o][x] += graph[o][prev]; //累加值
        prev = x;
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
        
    }

    for(int i=0;i<Q;i++) {
        int l1,l2;
        cin >> l1 >> l2;
        if(find(l1) != find(l2)) {
            cout << "UNKNOWN" << endl;
            continue;
        }   
        cout << graph[l2][l1-1] << endl;
    }
    return 0;
}