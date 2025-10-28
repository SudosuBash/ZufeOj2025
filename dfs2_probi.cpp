/**
 * 迷宫/bfs
 * 目标:理解bfs算法的逻辑
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int x;
    int y;
    int step;
}pos;

pos queuec[1001];
int head = 0,tail = 0;
int used[101][101];
char qipan[101][101];

void enqueue(pos x) {
    queuec[tail] = x;
    tail += 1;
}

pos dequeue() {
   return queuec[head++];
}

void bfs(int n1,int n2,int targetX,int targetY) {
    while (head != tail) {

        pos p = dequeue();

        if (used[p.x][p.y] == 1 || qipan[p.x][p.y] != '.') {
            continue;
        }
        // cout << p.x << " " << p.y << endl;
        used[p.x][p.y] = 1;
        if (p.x == targetX && p.y == targetY) {
            cout << p.step << endl;
            return;
        }
        int nx1 = p.x+1,nx2 = p.x-1;
        int ny1 = p.y+1,ny2 = p.y-1;
        if (nx1 < n1) {
            pos p2 = {nx1,p.y,p.step+1};
            enqueue(p2);
        }
        if (nx2 >= 0) {
            pos p2 = {nx2,p.y,p.step+1};
            enqueue(p2);
        }
        if (ny1 < n2) {
            pos p2 = {p.x,ny1,p.step+1};
            enqueue(p2);
        }
        if (ny2 >= 0) {
            pos p2 = {p.x,ny2,p.step+1};
            enqueue(p2);
        }
    }
}

int main() {
    int n1,n2;
    cin >> n1 >> n2;
    for (int i=0;i<n1;i++) {
        for (int j=0;j<n2;j++) {
            cin >> qipan[i][j];
        }
    }
    pos p = {0,0,1};
    enqueue(p);
    bfs(n1,n2,n1-1,n2-1);
    return 0;
}