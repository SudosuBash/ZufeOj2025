#include "bits/stdc++.h"

using namespace std;

int num[100001];
int que[100001];
int main() {
    int n;
    cin >> n;
    int l = 0,r = 0;
    int cmax = 0;
    for(r=0;r<n;r++) {
        int t;
        cin >> t;
        que[r] = t;
        if(num[t]) {
            cmax = max(r-l,cmax);
            while(num[t]) {
                num[que[l]] = 0;
                l+=1;
            }
        } 
        num[t] = 1;
    }
    cmax = max(r-l,cmax);
    cout << cmax;
    return 0;
}