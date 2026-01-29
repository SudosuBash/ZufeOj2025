#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/**
 * Luogu P8622
 * 相当于原来灯全部是开着的，第一次所有编号为1的倍数光源操作一次把它关掉了(题目没说)
 *  - 只有奇数个因子个数的灯才能关得掉!
 *  - 只有完全平方数的因子个数才是奇数!
 * 问题转化: 求 [L,R] 内完全平方数的个数?
 */
int main() {
    ll N,L,R;
    cin >> N >> L >> R;
    ll r1 = (ll)(sqrt(R)); 
    ll r2 = (ll)(sqrt(L-1));
    //r1 - r2 是因子数量
    //R - (L - 1) 是所求范围内所有灯的数量
    cout << R - (L - 1) - (r1 - r2);

    return 0;
}   
