#include "bits/stdc++.h"

using namespace std;

int range[100001] = {0};

int find_erfen_l(int n,int size) {
    int l=0,r=size-1;
    int a = 0;
    while(l<=r) {
        int med = (l+r) / 2;
        if(range[med] >= n) {
            if(range[med] == n) {
                a = 1;
            }
            r=med-1;
        } else {
            l = med+1;
        }
    }
    if(a==1) return l;  
    else return -1;
}

int find_erfen_r(int n,int size) {
    int l=0,r=size-1;
    int a = 0;
    while(l<=r) {
        int med = (l+r) / 2;
        if(range[med] > n) {

            r=med-1;
        } else {
            if(range[med] == n) {
                a = 1;
            }
            l = med+1;
        }
    }
    if(a==1) return r;
    else return -1;
}
int main() {
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++) {
        cin >> range[i];
    }
    for(int i=1;i<=q;i++) {
        int n1;
        cin >> n1;
        cout << find_erfen_l(n1,n) << " " << find_erfen_r(n1,n) << endl;
    }
    return 0;
}