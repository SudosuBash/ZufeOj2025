#include <bits/stdc++.h>

using namespace std;

int oi_6192_probc_map[1001][1001] = {};
int oi_6192_probc_used[1001][1001] = {};
typedef struct {
    int step;
    int x;
    int y;
} step_t;

queue<step_t> qst;
int startX,startY,endX,endY;
void init_map(int n,int m) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char c;
            cin >> c;
            switch(c) {
                case 'S': {
                    oi_6192_probc_map[i][j] = 1; 
                    startX = i;
                    startY = j;
                    break;
                }
                case '#': oi_6192_probc_map[i][j] = 2; break;
                case 'T': {
                    oi_6192_probc_map[i][j] = 3;
                    endX = i;
                    endY = j;
                    break;
                }
                default: oi_6192_probc_map[i][j] = 0;break;
            }
        }
    }
}
int main() {
    int n,m;
    cin >> n >> m;
    init_map(n,m);
    step_t st1 = {
        .step = 0,
        .x = startX,
        .y = startY
    };
    qst.push(st1);
    while(qst.size() != 0) {
        step_t st = qst.front();
        qst.pop();
        int fx = st.x + 1,bx = st.x - 1;
        int fy = st.y + 1, by = st.y - 1;
        
        if(st.x < 0 || st.x >= n) {
            continue;
        }
        if(st.y < 0 || st.y >= m) {
            continue;
        }
        if(oi_6192_probc_used[st.x][st.y]) {
            continue;
        }
        if(oi_6192_probc_map[st.x][st.y] == 2 ) {
            continue;
        }
        if(oi_6192_probc_map[st.x][st.y] == 3) {
            cout << st.step;
            break;
        }
        oi_6192_probc_used[st.x][st.y] = 1;
        step_t st2 = {
            .step = st.step + 1,
            .x = st.x,
            .y = st.y
        };
        st2.x = fx;
        qst.push(st2);
        st2.x = bx;
        qst.push(st2);
        st2.x = st.x;
        st2.y = fy;
        qst.push(st2);
        st2.y = by;
        qst.push(st2);
    }
    return 0;
}