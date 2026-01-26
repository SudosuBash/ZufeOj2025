#include <bits/stdc++.h>

using namespace std;

int a[10001] = {0};
int main() {
    int minIndex = 10002,maxIndex = 0;
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        int id;
        while(cin >> id) {
            minIndex = min(minIndex,id);
            maxIndex = max(maxIndex,id);
            a[id] += 1;
        }
    }

    int lost = 0,corrupt = 0;
    for(int i=minIndex;i<=maxIndex;i++) {
        if(a[i] == 0) lost = i;
        if(a[i] == 2) corrupt = i;
    }

    cout << lost << " " << corrupt << endl;
    return 0;
}