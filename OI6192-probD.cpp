#include <bits/stdc++.h>

using namespace std;

#define LEFT_WALL(x) ((x) & 1)
#define UP_WALL(x) (((x) >> 1) & 1)
#define RIGHT_WALL(x) (((x) >> 2) & 1)
#define DOWN_WALL(x) (((x) >> 3) & 1)


int migong[1001][1001] = {0};
int mig_used[1001][1001] = {0};
int m,n;
//m:南北
//n: 东西
/**
 * 以下是判定可走的
 */
#define LEFT_IS_WALKABLE(x,y) ((x) - 1 >= 0 && !mig_used[y][(x)-1])
#define UP_IS_WALKABLE(x,y) ((y) - 1 >= 0 && !mig_used[(y)-1][x])
#define RIGHT_IS_WALKABLE(x,y) ((x) + 1 < n && !mig_used[y][(x)+1])
#define DOWN_IS_WALKABLE(x,y) ((y) + 1 < m && !mig_used[y+1][x])

/**
 * 以下是判定单块面积的
 */
#define LEFT_IS_VALID(x,y) (!LEFT_WALL(migong[(y)][(x)]) && LEFT_IS_WALKABLE(x,y))
#define RIGHT_IS_VALID(x,y) (!RIGHT_WALL(migong[(y)][(x)]) && RIGHT_IS_WALKABLE(x,y))
#define UP_IS_VALID(x,y) (!UP_WALL(migong[(y)][(x)]) && UP_IS_WALKABLE(x,y))
#define DOWN_IS_VALID(x,y) (!DOWN_WALL(migong[(y)][(x)]) && DOWN_IS_WALKABLE(x,y))

typedef struct {
    int x;
    int y;
} step_t;
queue<step_t> st;
int sl1 = 0,maxS = 0;
void bfs(int x,int y) {
   step_t s1 = {
    .x = x,
    .y = y
   };
   st.push(s1);
   int s = 0;
   while(st.size() != 0) {
        step_t s2 = st.front();
        st.pop();
        if(mig_used[s2.y][s2.x]) continue;
        s+=1;
        mig_used[s2.y][s2.x] = 1;
        step_t s3 = s2;
        if(LEFT_IS_VALID(s2.x,s2.y)) {
            s3.x = s2.x - 1;
            st.push(s3);
        }
        if(RIGHT_IS_VALID(s2.x,s2.y)) {
            s3.x = s2.x + 1;
            st.push(s3);
        }
        s3.x = s2.x;
        if(UP_IS_VALID(s2.x,s2.y)) {   
     
            s3.y = s2.y - 1;
            st.push(s3);
        }
        if(DOWN_IS_VALID(s2.x,s2.y)) {
            s3.y = s2.y + 1;
            st.push(s3);
        }
        if(st.size() == 0) {
            sl1 += 1;
            maxS = max(s,maxS);
        }
   }
}
int main() {
    cin >> m >> n;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin >> migong[i][j];
        }
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(!mig_used[i][j]) {
                bfs(j,i);
            }
        }
    }
    cout << sl1 << endl << maxS;
    return 0;
}