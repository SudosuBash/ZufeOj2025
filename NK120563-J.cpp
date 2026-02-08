#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll search_depth(ll n) {
    ll k = 2;
    while(k <= n) {
        k*=2;
    }
    return k / 2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T;
    cin >> T;
    for(int i=1;i<=T;i++) {
        ll n;
        int q;
        cin >> n >> q;
        ll kstart = search_depth(n);
        for(int j=1;j<=q;j++) {
            ll c;
            cin >> c;
            ll start = search_depth(c);
            if(start != kstart) {
                cout << start << endl;
            } else {
                cout << n - kstart + 1 << endl;
            }
        }
    }

}