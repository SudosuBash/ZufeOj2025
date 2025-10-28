#include <bits/stdc++.h>
using namespace std;

void kuaipai(vector<int>& v,int left,int right) {
    int i=left,j=right;
    if (left >= right) return;
    int base = v[left];
    while (i<j) {
        while (v[j] >= base && i<j) {
            j--;
        }
        while (v[i] <= base && i<j) {
            i++;
        }
        int c = v[i];
        v[i] = v[j];
        v[j] = c;
    }
    int c = v[i];
    v[i] = v[left];
    v[left] = c;
    kuaipai(v,left,i);
    kuaipai(v,i+1,right);
}
int main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(5);
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    kuaipai(v,0,v.size()-1);
    return 0;
}