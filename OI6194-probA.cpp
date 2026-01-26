#include <bits/stdc++.h>

#define left first
#define right second

using namespace std;

typedef struct {
    pair<int,int> p;
    int i;
} pi_t;

int len = 1;
void calcHeight(pi_t* arr,int index,int currentLen) {
    if(arr[index].p.left != 0) {
        calcHeight(arr,arr[index].p.left,currentLen+1);
    }
    if(arr[index].p.right != 0) {
        calcHeight(arr,arr[index].p.right,currentLen+1);
    }
    if(arr[index].p.left == 0 && arr[index].p.right == 0) {
        len = max(currentLen, len);
    }
}
int main() {
    pi_t arr[1001];
    int n;
    cin >> n;

    for(int idx=1;idx<=n;idx++) {
        pi_t p;
        cin >> p.i;
        cin >> p.p.left;
        cin >> p.p.right;
        arr[idx] = p;
    }
    calcHeight(arr,1,1);
    cout << len << endl;
    return 0;
}