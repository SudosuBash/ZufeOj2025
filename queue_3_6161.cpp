//bfs
#include <bits/stdc++.h>
using namespace std;

char migong[101][101];
int vis[101][101];

typedef struct {
    int x;
    int y;
    int step;
} tmp1;
queue<tmp1> p;
int bfs(int n1,int n2) {
    while(p.size() != 0) {
        tmp1 t = p.front();
        p.pop();
        
        if(vis[t.x][t.y] || migong[t.x][t.y] == '#') {
            continue;
        }
        vis[t.x][t.y] = 1;
        if(migong[t.x][t.y] == 'T') {
            return t.step;
        }
        int x = t.x,y=t.y;
        int nx1 = x+1,nx2 = x-1;
        int ny1 = y+1,ny2 = y-1;
        if(nx1 <= n1) {
            tmp1 t1 = {nx1,y,t.step +1 };
            p.push(t1);
        }

        if(ny2 >= 1) {
            tmp1 t1 = {x,ny2,t.step + 1};
            p.push(t1);
        }

        if(nx2 > 0) {
            tmp1 t1 = {nx2,y,t.step + 1};
            p.push(t1);
        }
        if(ny1<=n2) {
            tmp1 t1 = {x,ny1,t.step + 1};
            p.push(t1);
        }
    }
    return 0;
}
int main() {
    int n1,n2;
    cin >> n1 >> n2;
    for(int i=1;i<=n1;i++) {
        for(int j=1;j<=n2;j++) {
            cin >> migong[i][j];
        }
    }
    tmp1 t;
    t.x = 1;
    t.y = 1;
    t.step = 0;
    p.push(t);
    cout << bfs(n1,n2);
    return 0;
}