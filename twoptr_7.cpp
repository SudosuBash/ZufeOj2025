#include <bits/stdc++.h>

using namespace std;

int t7_distance[100001] = {0};
int check(int dis,int C,int N) {
    int prevDis = 1;
    int cnt = 1;
    for(int i=2;i<=N;i++) {
        if(t7_distance[i] - t7_distance[prevDis] >= dis) {
            cnt++;
            prevDis = i;
        }
    }
    if(cnt >= C) return 1;
    return 0;
}
int main() {  
    int N,C;
    cin >> N >> C;
    for(int i=1;i<=N;i++) {
        cin >> t7_distance[i];
    }
    sort(t7_distance+1,t7_distance+N+1);

    int l=1,r=t7_distance[N];
    while(l<=r) {
        int med = (l+r) / 2;
        if(check(med,C,N)) {
            l = med + 1;
        } else {
            r = med - 1;
        }
    }
    cout << r << endl;
    return 0;
}