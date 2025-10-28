#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string res;
    int find = 0;
    for (int i = 0; i < n; i++) {
        string c;
        cin >> c;
        if (find) {
            res += c + "\n";
            continue;
        }
        if (c[0] == 'O' && c[1] == 'O') {
            c = "++" + c.substr(2, 3);
            find = 1;
        }
        if (c[3] == 'O' && c[4] == 'O') {
            c = c.substr(0,3)+"++";
            find = 1;
        }
        res += c + "\n";
    }
    if (find) {
        cout <<"YES" << endl;
        cout << res;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}