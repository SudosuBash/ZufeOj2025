/**
 * Problem E: 小杨的队列
 * 插入排序
 */
#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<int> sgs;
    vector<int> seq;
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        int sg;
        cin >> sg;
        sgs.push_back(sg);
    }

    int c;
    cin >> c;
    for (int i=0;i<c;i++) {
        int a0;
        cin >> a0;
        seq.push_back(sgs[a0]); //a0最后一位
        int index = seq.size()-1;
        int value = sgs[a0];
        int res = 0;
        while (index >= 0 && seq[index] > value) {
            seq[index] = seq[index-1];
            index --;
            res++;
        }
        seq[index] = value;
        cout << res << endl;
    }
    return 0;
}