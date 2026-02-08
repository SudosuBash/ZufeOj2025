#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll cprev[100001] = {0};
ll ys[100001] = {0};
int main() {
    int N,K;
    cin >> N >> K;
    ll res = 0;
    for(int i=1;i<=N;i++) {
        ll c;
        cin >> c;
        cprev[i] = cprev[i-1] + c;
        ll modc = cprev[i] % K;
        ys[modc] += 1;
    }
    res += ys[0]*(ys[0]+1) / 2;
    for(int i=1;i<K;i++) {
        res+=ys[i]*(ys[i]-1) / 2;
    }

    cout << res << endl;
    return 0;
}