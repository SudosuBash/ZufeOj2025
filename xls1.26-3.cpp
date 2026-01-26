#include <bits/stdc++.h>
using namespace std;

#define max_c 1000001
int arr[max_c] = {0};

int next_bucket[max_c] = {0};
int next(int i) { 
    //并查集
    if(next_bucket[i] == -1) {
        return i;
    }
    int f = next(next_bucket[i]); //返回的是第一个未被使用的索引
    next_bucket[i] = f; 
    return f;
}
int main() {
    int N;
    cin >> N;
    for(int i=0;i<max_c;i++) {
        next_bucket[i] = -1;
    }
    for(int i=0;i<N;i++) {
        int n;
        scanf("%d",&n);
        n = next(n); //此时此刻,n=未使用的索引
        next_bucket[n] = n + 1; //更新为下一个索引
        arr[i] = n;
    }

    for(int i=0;i<N;i++) {
        cout << arr[i] << " " ;
    }
}