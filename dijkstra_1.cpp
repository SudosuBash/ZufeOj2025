#include <bits/stdc++.h>
using namespace std;

int graph[10001][10001];

void initGraph(int n) {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<i;j++) {
            int c = graph[i][j]; //路线i->j
            
        }
    }
}
int main() {
    int n,m,S,T;
    cin >> n >> m >> S >> T;
    for(int i=0;i<m;i++) {
        int x,y,c;
        cin >> x >> y >> c;
        graph[x][y] = c;
    }

    initGraph(n);

}