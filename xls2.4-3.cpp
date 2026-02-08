#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c[101] = {0};

int maxgys = 0;
int gys(int x,int y) {
    while(x%y!=0) {
        int c = x%y;
        x=y;
        y=c;
    }
    return y;
}
int main() {
    int N;
    cin >> N;
    for(int i=0;i< N;i++) {
        cin >> c[i];
        maxgys = gys(c[i],maxgys);
    }
    
    if(maxgys!=1) {
        cout << "INF" << endl;
        return 0;
    }
    
    return 0;
}