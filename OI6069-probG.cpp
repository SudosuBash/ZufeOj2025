#include <bits/stdc++.h>

using namespace std;


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    cin >> T;
    for (int i=0;i<T;i++) {
        int n;
        cin >> n;
        int used[300001] = {0};
        for (int j=0;j<n;j++) {

            int x;
            cin >> x;
            if (j + x < n) {
                used[j+x] = 1;
            }
            if (j-x >= 0) {
                used[j-x] = 1;
            }
        }
        int l = 0;
        for (int j=0;j<n;j++) {
            l+= 1 - used[j];
        }
        cout << l-1 << endl;
    }

    return 0;
}