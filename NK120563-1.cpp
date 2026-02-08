#include <bits/stdc++.h>
using namespace std;

int zjda[101] = {0};

void init() {
    for(int i=1;i<=100;i++) {
        if(i*(i+1) > 100) break;
        zjda[i*(i+1)] = 1;
    }
}
int main() {
    int n;
    cin >> n;
    init();
    if(zjda[n]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}