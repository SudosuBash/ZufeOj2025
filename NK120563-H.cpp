#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll x1,y1;
    ll x2,y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    if(y2 ==  y1) {
        if(abs(y2*(x2-x1)) == 4) {
            printf("%.10f\n",0); //实数?
            return 0;
        }
        cout << "no answer" << endl;
        return 0;
    } else {
        ll dy = (y1 - y2); 
        ll ax = (4+x2*y1-x1*y2);
        double ans = (double)(ax) / (double)(dy);
        printf("%.10f\n",ans); //实数?
    }
    return 0;
}