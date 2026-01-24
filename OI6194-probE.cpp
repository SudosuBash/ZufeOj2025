#include <bits/stdc++.h>

using namespace std;

int graph[101][101] = {0};
int main() {
    int n;
    while(cin >> n) {
        while(1) {
            int x,y;
            cin >> x >> y;
            if(x==0 && y==0) break;
            graph[x][y] = 1;
        }   
        for(int i=1;i<=n;i++) {
            int out = 0;
            for(int j=1;j<=n;j++) {
                out += graph[i][j];
            }
            cout << out << " ";
        }

        cout << endl;
        for(int i=1;i<=n;i++) {
            int in = 0;
            for(int j=1;j<=n;j++) {
                in += graph[j][i];
            }
            cout << in << " ";
        }
   

    }
}