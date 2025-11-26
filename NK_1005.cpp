#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int pai[21] = {0};
    for (int i=0;i<n;i++) {
        cin >> pai[i];
    }
    int shunzi = 0;
    for (int i=0;i<=n-5;i++) {
        if (pai[i+1] == pai[i]+1 &&
            pai[i+2] == pai[i+1]+1 &&
            pai[i+3] == pai[i+2]+1 &&
            pai[i+4] == pai[i+3]+1) {
            cout << "Shun Zi" << endl;
            shunzi = 1;
            return 0;
            }
    }
    cout << "Dan Zhang" << endl;
    return 0;
}