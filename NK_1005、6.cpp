#include <bits/stdc++.h>
using namespace std;

int statistics[100001] = {0};
int main() {
    int n;
    cin >> n;

    int found = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        statistics[k]++;
        if (statistics[k] > n/2 && !found) {
            cout << k << endl;
            found = 1;
        }
    }
    return 0;
}