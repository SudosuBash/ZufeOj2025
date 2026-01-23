#include <bits/stdc++.h>

using namespace std;

int main() {
    queue<int> q;
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        q.push(i);
    }
    int i = 1;
    while(q.size() != 0) {
        int c = q.front();
        q.pop();
        if(i % m != 0) {
            q.push(c);
        } else {
            cout << c << " ";
            i = 0;
        }
        i = i+1;
    }
    return 0;
}