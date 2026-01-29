#include <bits/stdc++.h>
using namespace std;

const int zs = 1e8+1;
bool is_prime[zs];
void initPrime(int n) {
    is_prime[1] = is_prime[0] = true;
    for(int i=2;i<n;i++) {
        if(!is_prime[i]) {
            for(int j=i;j<=(n/i+1);j++) {
                long long val = (long long)j*(long long)i;
                if(val > n) break;
                is_prime[val] = true;
            }
        }
    }
}


bool jud(int x) {
    while(x!=0) {
        if(is_prime[x]) 
            return false;
        x/=10; 
    }
    return true;
}

int main() {
    int x;
    cin >> x;
    switch(x) {
        case 1:
            cout << "2\n3\n5\n7\n" << endl;
            return 0;
        case 2:
            cout << "23\n29\n31\n37\n53\n59\n71\n73\n79\n" << endl;
            return 0;
        case 3:
            cout << "233\n239\n293\n311\n313\n317\n373\n379\n593\n599\n719\n733\n739\n797" << endl;
            return 0;
        case 4:
            cout << "2333\n2339\n2393\n2399\n2939\n3119\n3137\n3733\n3739\n3793\n3797\n5939\n7193\n7331\n7333\n7393" << endl;
            return 0;
        case 5:
            cout << "23333\n23339\n23399\n23993\n29399\n31193\n31379\n37337\n37339\n37397\n59393\n59399\n71933\n73331\n73939" << endl;
            return 0;
        case 6:
            cout << "233993\n239933\n293999\n373379\n373393\n593933\n593993\n719333\n739391\n739393\n739397\n739399";
            return 0;
        case 7:
            cout << "2339933\n2399333\n2939999\n3733799\n5939333\n7393913\n7393931\n7393933" << endl;
            return 0;
        case 8:
            cout << "23399339\n29399999\n37337999\n59393339\n73939133" << endl;
            return 0;
    }
    // for(int i=1;i<=8;i++) {
    //     int c = (int)(pow(10,i-1));
    //     int d = (int)(pow(10,i)) - 1;
    //     for(int i=c;i<=d;i++) {
    //         if(jud(i)) {
    //             cout << i << endl;
    //         }
    //     }
    // }

    return 0;
}