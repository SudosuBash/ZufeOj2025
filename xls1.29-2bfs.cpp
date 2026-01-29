#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int x;
    int y;
    int maxval;
    int bw;
} step_t;
int value[101][101] = {0};
int n,m,k;
int res = 0;

queue<step_t> st;
void bfs() {
    step_t ob1 = {
        .x = 1,
        .y = 1,
        .maxval = value[1][1],
        .bw = 1
    };
    st.push(ob1);
    ob1.maxval = 0;
    ob1.bw = 0;
    st.push(ob1);
    while(!st.empty()) {
        step_t ob2 = st.front();
        st.pop();
        if(ob2.x == n && ob2.y == m) {
            if(ob2.bw == k) {
                res++;
                continue;
            }
        }
        step_t ob3;
        if(value[ob2.y][ob2.x+1] > ob2.maxval && ob2.x+1 <= n) {
            ob3.x = ob2.x+1;
            ob3.y = ob2.y;
            ob3.maxval = value[ob3.y][ob3.x];
            ob3.bw = ob2.bw + 1;
            st.push(ob3);
        }
        if(value[ob2.y+1][ob2.x] > ob2.maxval && ob2.y+1 <= m) {
            ob3.x = ob2.x;
            ob3.y = ob2.y+1;
            ob3.maxval = value[ob3.y][ob3.x];
            ob3.bw = ob2.bw + 1;
            st.push(ob3);
        }
        if(ob2.x+1 <= n) {
            ob3.x = ob2.x + 1;
            ob3.y = ob2.y;
            ob3.maxval = ob2.maxval;
            ob3.bw = ob2.bw;
            st.push(ob3);
        }
        if(ob2.y+1 <= m) {
            ob3.x = ob2.x;
            ob3.y = ob2.y +1;
            ob3.maxval = ob2.maxval;
            ob3.bw = ob2.bw;
            st.push(ob3);
        }

    }
}
int main() {
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> value[i][j];
        }
    }
    bfs();
    cout << res << endl;
    return 0;
}