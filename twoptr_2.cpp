#include "bits/stdc++.h"

using namespace std;

char str[100001];
int main() {
    
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++) {
        cin >> str[i];
    }
    // for(int i=1;i<=n;i++) {
    //     int j;
    //     for(j=i-1;j>0;j--) {
    //         if(str[i] == str[j]) break;
    //     }
    //     dp[i] = dp[j] + 1;
    // }
    int l = 1,r = l;
    int tk = 0;
    int maxk =0;
    while(l <= n && r<=n) {
        while(tk <= k && r <= n) {
            if(str[r] == 'a') {
                if(tk == k) break;
                tk++;
            }
            r++;
        }
        maxk = max(maxk,r-l);
        while(tk == k && l<r) {
            if(str[l] == 'a') tk--;
            l++;
        }
    }
    tk
    =0,l=1,r=l;
    while(l <= n && r<=n) {
        while(r <= n) {
            if(str[r] == 'b') {
                if(tk == k) break;
                tk++;
            }
            r++;
        }
        maxk = max(maxk,r-l);
        while(tk == k && l<r) {
            if(str[l] == 'b') tk--;
            l++;
        }
    }
    cout << maxk << endl;
    return 0;
}