#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int ninecount(ll x) {
    int n = 0;
    queue<int> q;
    while(x!=0) {
        q.push(x %10);

        if(x%10!=9) n+=1;
        x/=10;
    }
    return (n == 1 && q.back() != 9) || n == 0;
}

ll proc1(ll l,ll r) {
    stack<int> st1,st2;
    while(r!=0) {
        st2.push(r%10);
        r/=10;
    }
    while(l!=0) {
        st1.push(l%10);
        l/=10;
    }
    for(int i=st1.size();i<st2.size();i++) {
        st1.push(0);
    }

    ll res = 0;
    int c1 = st1.top(),c2 = st2.top();
    st1.pop();
    st2.pop();
    while(!st2.empty() && c2 == c1) {
    
        res *= 10;
        res += c1;
    label: //1的特殊对待
        c1 = st1.top();
        c2 = st2.top();
        st1.pop();
        st2.pop();
    }
    
    if(c2!=c1) {
        if(res == 0 && c2 == 1) goto label;
        if(!st2.empty()) c2-=1;
        //不是个位,需要减1
        res*=10;
        res+=c2;
    } else {
        res*=10;
        res+=c2;
    }

    while(!st2.empty()) {
        res*=10;
        res+=9;
        st2.pop();
    }
    return res;
}

ll reversec(ll x) {
    ll r = 0;
    while(x!=0) {
        r=r*10+(x%10);
        x/=10;
    }
    return r;
}
int main() {
    int T;

    cin >> T;
    for(int i=0;i<T;i++) {
        ll l,r;
        cin >> l >> r;
        if(ninecount(r)) {
            cout << reversec(r) << endl;
            continue;
        }
        ll c = proc1(l,r);
        cout << reversec(c) << endl;
    }
    // cout << proc1(40000,46000) << endl;
}