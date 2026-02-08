#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int gcd(int x,int y) {
    while(x%y!=0) {
        int b = x%y;
        x=y;
        y=b;
    }
    return y;
}
void solve() {
    int n;
    cin >> n;
    v.clear();
    for(int i=1;i<=n;i++) {
        int ai;
        cin >> ai;
        v.push_back(ai);
    }
    for(int i=0;i<v.size();i++) 
        for(int j=i+1;j<v.size();j++) {
            if(gcd(v[i],v[j])!=1) {
                cout << v[i] << " " << v[j] << endl;
                return;
            }
        }
    cout << "-1" << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int i=1;i<=T;i++) {
        solve();
    }
}