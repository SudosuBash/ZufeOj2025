#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int next;
    int to;
} node_t;

node_t ndt[101] = {0};
int cnt = 0;
int head[101] = {0};
int rudu[101] = {0}, chudu[101] = {0};
void add(int u, int v) { //头插
    //从u到v
    cnt++;
    ndt[cnt].next = head[u];
    ndt[cnt].to = v;
    head[u] = cnt;
    //它在干什么? 见ppt
}

void init() {
    for(int i=0;i<101;i++) {
        head[i] = -1;
    }
}

void get_rudu_chudu() {
    for(int i=0;i<=100;i++) {
        for(int j = head[i]; j!=-1; j=ndt[j].next) {
            rudu[i] += 1;
            chudu[ndt[j].to] += 1;
        }
    }
}
int main() {

}