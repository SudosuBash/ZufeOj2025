#include <bits/stdc++.h>
using namespace std;

#define hi first
#define wi second
typedef pair<int,int> pii;
vector<pii> vp;

int judge(int ci,int person) {
    int aks = 0;
    for(int i=0;i<vp.size();i++) {
        pii p = vp[i];
        int ks = (p.hi / ci)*(p.wi / ci);
        aks+=ks;
    }
    return aks >= person;
}
int erfen(int r,int person) {
    int l=1;
    while(l<=r) {
        int m = (l+r) / 2;
        if(judge(m,person)) l=m+1;
        else r=m-1;
    }
    return r;
}
int main() {
    int N,K;
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        pii p;
        cin >> p.hi >> p.wi;
        vp.push_back(p);
    }
    cout << erfen(100001,K) << endl;
}