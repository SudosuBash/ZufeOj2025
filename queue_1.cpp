#include <bits/stdc++.h>
using namespace std;
int main() {
    int p1,p2;
    cin >> p1 >> p2;
    queue<int> q1,q2;
    int wuqu;
    cin >> wuqu;
    for(int i=1;i<=p1;i++) {
        q1.push(i);
    }
    for(int i=1;i<=p2;i++) {
        q2.push(i);
    }
    for(int i=1;i<=wuqu;i++) {
        int l1 = q1.front();
        int l2 = q2.front();
        q1.pop();
        q2.pop();
        cout << l1 << " " << l2 << endl;
        q1.push(l1);
        q2.push(l2);
    }
    return 0;
}