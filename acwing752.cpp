// ACWing 752 快排 - 第k个数
#include <bits/stdc++.h>

using namespace std;
int select(vector<int>& v,int left,int right,int k) {
    int base = v[left];
    int i=left,j=right;
    while (i<j) {
        while (i<j && v[j]>=base) {
            j--;
        }
        while (i<j && v[i] <= base) {
            i++;
        }

        int c = v[i];
        v[i] = v[j];
        v[j] = c;
    }
    int c = v[left];
    v[left]=v[i];
    v[i]=c;
    if (k==i) return v[k];
    if (i>k) return select(v,left,i,k);
    return select(v,i+1,right,k);
}
int main() {
    vector<int> v;
    int c;
    cin >> c;
    for (int i=0;i<c;i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }
    int v1;
    cin >> v1;
    cout << select(v,0,v.size()-1,v1-1) << endl;
    return 0;
}