#include <bits/stdc++.h>
using namespace std;

int main() {
    int days [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int cnt;
    cin >> cnt;
    for (int i = 1; i <= cnt; i++) {
        int n1,n2,n3;
        cin >> n1 >> n2 >> n3;
        if (n2 > 12 || n2 <= 0) {
            cout << "NO" << endl;
            continue;
        }
        days[1] = 28;
        if (n1 % 4 == 0 ) {
            if ((n1 % 100 != 0 ) || (n1 % 100 == 0 && n1 % 400 == 0)) days[1] = 29;
        }
        if (n3 <= 0 || n3 > days[n2-1]) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;

}