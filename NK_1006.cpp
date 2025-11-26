

#include <bits/stdc++.h>
using namespace std;

// int res[40][40] = {0};
int main() {
    int n;
    cin >> n;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         res[i][j] = 1;
    //     }
    // }
    int gezi = n*n;
    unsigned long long result=1; //方案
    n = (n+1) / 2;
    gezi -= n;
    for (int i = 1; i <= n; i++) {
        result = result * i;
    }
    cout << gezi << endl;
    cout << result << endl;
    return 0;
}