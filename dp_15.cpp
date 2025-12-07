#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int dp[10001];
int cmp(pair<int,int> p1,pair<int,int> p2) {
    return p1.first < p2.first;
}
int main() {
    vector<pair<int,int>> vp;
    int num;
    cin >> num;
    for(int i=0;i<num;i++) {
        pair<int,int> p;
        cin >> p.first >> p.second;
        vp.push_back(p);
    }

    sort(vp.begin(),vp.end(),cmp);
    int res = 0;
    for(int i=1;i<=num;i++) {
        int tmp = 0;
        for(int j=1;j<i;j++) {
            if(vp[j-1].second < vp[i-1].second && dp[j] > tmp) tmp = dp[j];
        }
        dp[i]= tmp+1;
        if(dp[i] > res) res = dp[i];
    }
    cout << res << endl;
    return 0;
}