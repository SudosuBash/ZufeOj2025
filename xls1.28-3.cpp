#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int step;
    int x;
    int y;
} step_t;

queue<step_t> st;

char cmap[1001][1001] = {0};
int used[1001][1001] = {0};
int lx,ly;
int bfs(int sx,int sy) {
    step_t s0;
    s0.step = 0;
    s0.x = sx;
    s0.y = sy;
    st.push(s0);
    used[sy][sx] = 1;
    while(!st.empty()) {
        step_t s = st.front();
        st.pop();
        if(cmap[s.y][s.x] == 'B') return s.step;

        int pos[2] = {1,-1};
        for(int i=0;i<2;i++) {
            int nx = s.x+pos[i];
            int ny = s.y;
            if(!(used[ny][nx] ||
                ((nx >= lx || nx < 0) || (ny >= ly || ny < 0)) ||
                (cmap[ny][nx] == cmap[s.y][s.x]))) {
                step_t s2 = {
                    .step = s.step + 1,
                    .x = nx,
                    .y = ny
                };
                used[ny][nx] = 1;
                st.push(s2);
            }

            nx = s.x;
            ny = s.y+pos[i];
            if(!(used[ny][nx] ||
                ((nx >= lx || nx < 0) || (ny >= ly || ny < 0)) ||
                (cmap[ny][nx] == cmap[s.y][s.x]))) {
                step_t s2 = {
                    .step = s.step + 1,
                    .x = nx,
                    .y = ny
                };
                used[ny][nx] = 1;
                st.push(s2);
            }

            // if(used[ny][nx]) continue;

            // if((nx >= lx || nx < 0) || (ny >= ly || ny < 0)) continue;
            // if(cmap[ny][nx] == cmap[s.y][s.x]) continue;
            // s2 = {
            //     .step = s.step + 1,
            //     .x = nx,
            //     .y = ny
            // };
            // used[ny][nx] = 1;
            // st.push(s2);
        }  
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    lx = ly = n;
    int sx,sy;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> cmap[i][j];
            if(cmap[i][j] == 'A') {
                sx = j;
                sy = i;
            }
        }
    }
    cout << bfs(sx,sy) << endl;
    return 0;
}