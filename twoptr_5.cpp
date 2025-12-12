#include "bits/stdc++.h"
#include <stdio.h>
using namespace std;
int range[100001];
int main() {        
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&range[i]);
    }
    
    for(int i=1;i<=m;i++) {
        int f;
        scanf("%d",&f);
        int l=1,r=n;
        while(l <= r) {
            int mid = (l+r) / 2;
            if(range[mid] < f) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        printf("%d\n",l);
    }

    return 0;
}