//temporary not be solved.
#include <iostream>
#define inf 100000000
using namespace std;

typedef struct {
    int x;
    int y;
    int h;
} Brick;
Brick b[100001];
int main() {
    int c;
    do {
        cin >> c;
        int n;
        for(int i=1;i<=c;i++) {
            int a[3] = {0};
            cin >> a[0] >> a[1] >> a[2];
            sort(a,a+3,greater<int>());
            b[n].x = a[2];
            b[n].y = a[1];
            b[n].h = a[0];
            b[n+1].x = a[1];
            b[n+1].y = a[0];
            b[n+1].h = a[2];
            b[n+2].x = a[2];
            b[n+2].y = a[0];
            b[n+2].h = a[1];
            n+=3;
        }
    } while(c!=0);
    
}