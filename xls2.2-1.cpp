#include <bits/stdc++.h>
using namespace std;

int zf[101] = {0};
int main() {
    int n,a;
    cin >> n >> a;
    for(int i=0;i<n;i++) {
        cin >> zf[i];
    }
    a-=1;
    int res = 0;
    for(int i=0;i<100;i++) {
        int left = a - i,right = a + i;
        if(left == right && zf[left] == 1) {
            res++;
        } else if(left >= 0 && right < n && zf[left] + zf[right] == 2) {
            res+=2;
        } else if((left < 0 && right < n) && zf[right] == 1) {
            res++;
        } else if(right >= n && left >= 0 && zf[left] == 1) {
            res++;
        } else if(right>= n && left < 0) break;
    }
    cout << res << endl;
    return 0;
}