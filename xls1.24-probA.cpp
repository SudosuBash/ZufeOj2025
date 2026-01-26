#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ll a,b,n;
    cin >> a >> b >> n;

    ll day = 0;
    ll per_week = a*5+b*2;
    
    day = n / per_week * 7;
    ll left = n % per_week;

    while(left > 0) {
        for(int i=1;i<=5;i++) {
            day++;
            left -= a;
            if(left <= 0) goto end;
        }
        for(int i=1;i<=2;i++) {
            day++;
            left -= b;
            if(left <= 0) goto end;
        }
    }
    end:
    cout << day << endl;
    return 0;

}