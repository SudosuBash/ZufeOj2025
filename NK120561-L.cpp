#include<bits/stdc++.h>
using namespace std;

int main() {
    int c;
    cin >> c;
    for(int i=1;i<=10;i++) {
        if(c*i%10==0) {
            cout << i << endl;
            return 0;
        }
    }
}