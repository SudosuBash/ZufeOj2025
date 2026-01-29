#include <bits/stdc++.h>
using namespace std;

int collection[10001] = {0};
int bucket[10001] = {0}; //人数(不一定连续)
int bucket2[10001] = {0}; //社区个数
int f(int n) {
    int x = n;
    while(collection[n] != n)
        n = collection[n];
    collection[x] = n;
    return n;
}
int main() {
    int N;
    cin >> N;
    for(int i=0;i<=10000;i++) {
        collection[i] = i;
    }
    int sum_person = 0;
    for(int i=0;i<N;i++) {
        int K;
        cin >> K;
        int last = -1;
        for(int i=0;i<K;i++) {
            int dat;
            scanf("%d",&dat);
            if(bucket[dat] == 0) {
                sum_person += 1;
                bucket[dat] = 1;
            }
            int rx = f(dat);
            if(last != -1) {
                int ry = f(last);
                if(rx != ry) {
                    collection[ry] = rx;
                }
            }
            last = dat;
        }
    }
    
    int res = 0;
    int Q;
    cin >> Q;
    for(int i=1;i<=10000;i++) {
        if(bucket[i] == 1) {
            int index = f(i);
            if(bucket2[index] == 0) {
                res +=1;
                bucket2[index] = 1;
            }
        }
    }
    cout << sum_person << " " << res << endl;
    for(int i=0;i<Q;i++) {
        int q1,q2;
        scanf("%d%d",&q1,&q2);
        if(collection[q1]== collection[q2]) {
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }
    return 0;
}