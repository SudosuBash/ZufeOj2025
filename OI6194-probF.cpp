#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> in[101];
    vector<int> out[101];

    int n;

    while(cin >> n) {
        for(int i=0;i<n;i++) {
            in[i].clear();
            out[i].clear();
        }
        while(1) {
            int x,y;
            cin >> x >> y;
            if(x == 0 && y == 0 ){ //end...
                break;
            }
            in[x].push_back(y);
            out[y].push_back(x);
        }
        for(int i=1;i<=n;i++) {
            cout << in[i].size() << " ";
        }
        cout << endl;
        for(int i=1;i<=n;i++) {
            cout << out[i].size() << " ";
        }
        cout << endl;

        if(n == 0) {
            break;
        }
    }
    return 0;
}