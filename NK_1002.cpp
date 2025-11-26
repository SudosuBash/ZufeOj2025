#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    for (int i=0;i<n;i++) {
        //int a[150] = {0};
        unsigned long long a[150] = {0};
        int c;
        cin >> c;
        a[0] = 1;
        for (int j=0;j<c;j++) {
            a[j+1] += a[j];
            a[j+2] += a[j];
            a[j+3] += a[j];
        }
        cout << a[c] << endl;
    }
}