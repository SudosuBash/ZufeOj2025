#include <bits/stdc++.h>
using namespace std;

#define m 998244353
typedef long long ll;
ll calc(int l1,int l2) {
    ll res = 1;
    // if(l1 ==0) l1 = 1;
    // if(l2 == 0) l2 = 1;
    for(int i=1;i<=l1;i++) {
        res *= i;
        res %= m;
    }
    for(int i=1;i<=l2;i++) {
        res *= i;
        res %= m;
    }
    return res;
}
int main() {
    vector<int> v1;
    vector<int> v2;

    int T;
    cin >> T;
    for(int i=1;i<=T;i++) {
        v1.clear();
        v2.clear();
        int c;
        cin >> c;
        for(int j=1;j<=c;j++) {
            int v;
            cin >> v;
            v1.push_back(v);
        }

        for(int j=1;j<=c;j++) {
            int v;
            cin >> v;
            v2.push_back(v);
        }
        sort(v1.begin(),v1.end(),greater<int>());
        sort(v2.begin(),v2.end(),less<int>());

        int t = 0;
        for(int i=0;i<v1.size();i++) {
            if(v1[i] > v2[0]) t++;
        }
        int left = v1.size() - t;
        cout << calc(t,left) << endl;
    }

    return 0;
}