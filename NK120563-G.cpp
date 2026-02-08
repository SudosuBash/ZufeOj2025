#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v1,v2;
int main() {
    int T;
    cin >> T;
    for(int i=1;i<=T;i++) {
        int n,m;
        cin >> n >> m;
        v1.clear();
        v2.clear();
        ll sum1 = 0,sum2 = 0;
        for(int j=1;j<=n;j++) {
            ll ai;
            cin >> ai;
            v1.push_back(ai);
            sum1 += ai;
        }
        for(int j=1;j<=m;j++) {
            ll bi;
            cin >> bi;
            v2.push_back(bi);
            sum2 += bi;
        }
        if(sum1==sum2) {
            cout << "1" << endl;
            continue;
        }
        sort(v1.begin(),v1.end(),less<ll>());
        sort(v2.begin(),v2.end(),less<ll>());
        if(sum1 < sum2) {
            int c = 0;
            while(sum1 < sum2) {
                int dat = v2[v2.size()-1];
                v2.pop_back();
                sum2 -= dat;
                c+=1;
            }
            cout << c << endl;
            continue;
        } else if(sum1 > sum2) {
            int c = 0;
            while(sum1 > sum2) {
                ll dat = v1[v1.size()-1];
                v1.pop_back();
                sum1 -= dat;
                c+=1;
            }
            cout << c << endl;
            continue;
        }
    }
}