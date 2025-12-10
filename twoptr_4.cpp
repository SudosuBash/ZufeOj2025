#include "bits/stdc++.h"

using namespace std;
#define INF 123456789
int num[128];
int sig[128];
char str[100001];

int main() {
    int n;
    cin >> n;
    int allPz = 0;
    for(int i=0;i<n;i++) {
        cin >> str[i];
        if(!sig[str[i]]) allPz++;
        sig[str[i]] = 1;
    }
    int nowPz = 0;
    int l = 0;
    int res = INF;
    for(int r=0;r<n;r++) {
        if(!num[str[r]]) nowPz += 1;
        num[str[r]] += 1;

        while(nowPz == allPz) {
            res = min(res,r-l+1);
            num[str[l]] -= 1;
            if(num[str[l]] == 0) nowPz -= 1;
            l++;
        }
        
    }
    cout << res;
    return 0;
}