#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll arr[100001] = {0};
int main() {
    ll n,h,k;
    cin >> n >> h >> k;
    
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    ll proced = 1;
    ll proctime = 0;
    ll proclen = 0;
    while(proced <= n) {
        //h是限制高度
        while(proclen + arr[proced] <= h && proced <= n) {
            proclen+=arr[proced];
            proced++;
        }
        ll deltac = proclen + arr[proced] - h;
        ll needtime = (deltac + k - 1) / k; //向上取整
        proclen -= needtime * k;
        proctime += needtime;
        proclen = max(proclen,0ll);
    }
    proctime += (proclen + k - 1) / k;
    cout << proctime << endl;
    return 0;
}