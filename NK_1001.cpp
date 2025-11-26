#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int u1 = 6 * n + 3 - (n*2) - n - 2;
    for (int i=0;i<n*2;i++) {
        for (int j=0;j<n*2;j++) {
            cout << ".";
        }
        cout << "@";
        for (int j=0;j<n;j++) {
            cout << ".";
        }
        cout << "@";
        for (int j=0;j<u1;j++) {
            cout << ".";
        }
        cout << endl;
    }

    //中间一行
    cout << ".";
    for (int j=0;j<n*2;j++) {
        cout << "@";
    }
    for (int j=0;j<n;j++) {
        cout << ".";
    }
    cout << "@";
    u1 =6 * n + 3 - (n*2) - n - 2;
    for (int j=0;j<n;j++) {
        cout << ".";
    }
    cout << "@";

    for (int j=0;j<u1-3-n;j++) {
        cout << ".";
    }
    cout << "@.";
    cout << endl;


    for (int i=0;i<n*2-2;i++) {
        cout << ".@";
        for (int j=0;j<n*2-2;j++) {
            cout << ".";
        }
        cout << "@";
        for (int j=0;j<n;j++) {
            cout << ".";
        }
        cout << "@";
        u1 =6 * n + 3 - (n*2) - n - 2;
        for (int j=0;j<n;j++) {
            cout << ".";
        }
        cout << "@";

        for (int j=0;j<u1-3-n;j++) {
            cout << ".";
        }
        cout << "@." << endl;
    }

    cout << ".";
    for (int j=0;j<n*2;j++) {
        cout << "@";
    }
    for (int j=0;j<n;j++) {
        cout << ".";
    }
    cout << "@";
    u1 =6 * n + 3 - (n*2) - n - 2;
    for (int j=0;j<n;j++) {
        cout << ".";
    }
    cout << "@";

    for (int j=0;j<u1-3-n;j++) {
        cout << "@";
    }
    cout << "@.";
    cout << endl;
}