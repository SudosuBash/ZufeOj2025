#include <bits/stdc++.h>
// #define int long long int
using namespace std;
int n1,n2;
vector<int> v1;

vector<int> v2;
int used[100001] = {0};
int main() {
    cin >> n1 >> n2;
    for (int i = 1; i <= n1; i++) {
        int f;
        cin >> f;
        v1.push_back(f);
    }
    for (int i = 1; i <= n2; i++) {
        int f;
        cin >> f;
        v2.push_back(f);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    if (n1 > n2) {
        cout << "0" << endl;
        return 0;
    }

    int nowPaodan = 0;
    int nowGongcheng = 0;
    while (nowGongcheng < n1 && nowPaodan < n2) {
        if (v2[nowPaodan] > v1[nowGongcheng]) {
            used[nowPaodan] = 1;
            nowGongcheng++;
        }
        nowPaodan++;
    }
    if (nowGongcheng == n1) {
        long long sumc = 0;
        for (int i = 0; i < n2; i++) {
            if (used[i] == 0) sumc += v2[i];
        }
        cout << sumc << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}