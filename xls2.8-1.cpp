#include <bits/stdc++.h>
using namespace std;

int arr[1002] = {0};
int used[1002] = {0};
int main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    int infc = 0;
    int proced = 0;
    int ref = 0;
    while(proced < n) {
        for(int i=1;i<=n;i++) {
            if(!used[i] && arr[i] <= infc) {
                infc+=1;
                used[i] = 1;
                proced += 1;
            }
        }
        if(proced == n) break;
        ref+=1;
        for(int i=n;i>=1;i--) {
            if(!used[i] && arr[i] <= infc) {
                infc+=1;
                used[i] = 1;
                proced += 1;
            }
        }
        if(proced == n) break;
        ref+=1;
    }
    cout << ref << endl;
    return 0;
    
}