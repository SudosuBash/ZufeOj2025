#include <bits/stdc++.h>
using namespace std;
//int f1(int x) {
int f1(string x) {
    int len=0;
    if(x[len] != '1') return -1;
    for(len = 1;len < x.size();len++) {
        if(x[len]!='0') return -1;
    }
    return x.length() - 1;
    // for(len = x.size()-1;len>=0;len--) {
    //     zerocount+=(x[len] == '0');
    //     if(x[len] != '0') break;
    // }
    // if(len == 0 && x[len] == '1') return zerocount;
    // wc,你把我当傻子使呢
    // while(x!=0) {
    //     zerocount += (x%10 == 0);
    //     if(x%10!=0) {
    //         break;
    //     }
    //     x/=10;
    // }
    // if(x != 1) return -1;
    // return -1;
}
int main() {
    int n;
    cin >> n;
    int zerocount = 0;
    string tks = "1";
    for(int i=1;i<=n;i++) {
        string dat;
        cin >> dat;
        if(dat == "0") {
            cout << "0" << endl;
            return 0;
        }
        int zrc = f1(dat);
        if(zrc != -1) 
            zerocount += zrc;
        else tks = dat;
    }

    printf("%s",tks.c_str());
    for(int i=0;i<zerocount;i++) {
        printf("0");
    }
    return 0;
    
}