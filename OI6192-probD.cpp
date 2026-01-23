#include <bits/stdc++.h>

using namespace std;

#define LEFT_WALL(x) ((x) & 1)
#define UP_WALL(x) (((x) >> 1) & 1)
#define RIGHT_WALL(x) (((x) >> 2) & 1)
#define DOWN_WALL(x) (((x) >> 3) & 1)

int migong[1001][1001] = {0};
void solve() {

}
int main() {
    int m,n;
    cin >> m >> n;
    for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            cin >> migong[i][j];
        }
        
    }
}