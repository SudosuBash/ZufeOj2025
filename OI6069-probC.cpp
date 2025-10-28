#include <bits/stdc++.h>

using namespace std;

vector<int> cids;
int main() {
    int n,q;
    cin >> n >> q;

    for (int i=0;i<n;i++) {
        int cid;
        cin >> cid;
        cids.push_back(cid);
    }
    sort(cids.begin(),cids.end());
    for (int i=0;i<q;i++) {
        int bitsCode;
        cin >> bitsCode;

        int num;
        cin >> num;

        int find = 0;
        for (int j=0;j<cids.size();j++) {
            if (cids[j]%(int)pow(10,bitsCode) == num) {
                cout << cids[j] << endl;
                find = 1;
                break;
            }
        }
        if (find==0) {
            cout << "-1" << endl;
        }
        // int l=0,r=cids.size()-1;
        // while (l <= r) {
        //     int mid = (l+r)/2;
        //     int code = cids[mid] % bitsCode;
        //
        // }

    }

}