#include "bits/stdc++.h"

using namespace std;

int price[30001];
int main() {
    int w,n;
    cin >> w >> n;
    for(int i=1;i<=n;i++) {
        cin >> price[i];
    }
    sort(price+1,price+n+1);
    int zubie = 0;
    int l=1,r=n;
    while(l<r) {
        if(price[l] + price[r] <= w) {
            l++;
        }
        r--;
        zubie++; //配对不了的单独成一对
    }
    if(l==r) {
        zubie++;
    
    }
    // 这种贪心思路太慢
    // int w,n;
    // cin >> w >> n;
    // for(int i=1;i<=n;i++) {
    //     cin >> price[i];
    // }
    // int zubie = 0;
    // for(int i=1;i<=n;i++) {
    //     if(used[i]) continue;
    //     int require = 0;
    //     int mark = -1;
    //     for(int j=i+1;j<=n;j++) {
    //         if(price[i] + price[j] <= w) {
    //             if(price[j] > require && used[j] == 0) {
    //                 require = price[j];
    //                 mark = j;
    //             }
    //         }
    //     }
    //     if(mark != -1) 
    //         used[mark]= 1;
    //     used[i] = 1;
    //     zubie += 1;
    // }
    cout << zubie << endl;
    return 0;
}