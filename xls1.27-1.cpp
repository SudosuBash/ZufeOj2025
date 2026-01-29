#include <bits/stdc++.h>
using namespace std;
int pos[101] = {0};
int d[51] = {0};

queue<int> q;

int main() {
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        
        int dis;
        cin >> dis;
        
        if(pos[i] < 0) {
            d[i] = -1;
            pos[i] = -pos[i];
        } else {
            d[i] = 1;
        }
    }

    for(int i=0;i<n;i++) {
        
    }
}