#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100001] = {0};
int main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    sort(arr+1,arr+n+1);
    int numc = 1;
    ll arrc[3] = {0};
    arrc[0] = arr[1];
    for(int i=2;i<=n;i++) {
        if(arr[i] != arr[i-1]) {
            if(numc < 3) {
                arrc[numc] = arr[i]; 
            }
            numc+=1;
        }
    }
    if(numc > 3) {
        cout << "NO" << endl;
        return 0;
    }
    if(numc == 3) {
        if((arrc[0] + arrc[2])  == arrc[1] * 2) {
            cout << "YES" << endl;
            return 0;
        }
        cout << "NO" << endl;
        return 0;
    }


    if(numc == 2 || numc == 1) {
        cout << "YES" << endl;
        return 0;
    }
    return 0;
}