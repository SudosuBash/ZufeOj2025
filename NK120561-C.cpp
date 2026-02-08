#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll arr[1000001] = {0};
int main() {
    int T;
    cin >> T;

    
    for(int i=1;i<=T;i++) {
        int n;
        cin >> n;
        ll max_element = 0;
        for(int j=1;j<=n;j++) {
            ll t;
            cin >> t;
            arr[j] = t;
            if(t > max_element) {
                max_element = t;
            }
        }
        ll res = 0;
        res += max_element * (n-2);
        res += (arr[1]+arr[n]);
        // if(max_index == 1) {
            
        //     res += arr[n];
        // } else if(max_index == n) {
        //     res += max_element * (n-1);
            
        // } else {
        //     res += max_element*(n-2);
        //     res+=arr[1]+arr[n];
        // }
        cout << res << endl;
    }

}