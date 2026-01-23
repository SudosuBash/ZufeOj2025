#include <bits/stdc++.h>

using namespace std;
int main() {
    stack<int> s;
    int l;
    cin >> l;
    while(l!=0) {
        s.push(l&1);
        l>>=1;
    }
    while(!s.empty()) {
        
        cout << s.top();
        s.pop();
    }
    
    return 0;
}