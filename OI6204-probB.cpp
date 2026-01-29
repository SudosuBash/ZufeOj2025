#include <bits/stdc++.h>
using namespace std;
/**
 * 反素数定义:
 *  任意 0 < i < x, 均有 g(x) > g(i)
 *  g(x)是 x 的因子个数
 * 推论1: 对于因子个数为n的所有数字, 反素数是最小的那个.
 *  证明: 令 s,t 使得 g(s) = g(t) = n, 其中 t > s.
 *      则有 t > s 并且 g(t) 不大于 g(s), 不符合定义。
 *      所以 s 是因子个数为n的最小的数字.
 * 
 * 推论2: 对于任意反素数 s, 若质因子单调递增，则其指数幂必然单调递增.
 *  证明: 假设 Bi > Bi+1, s1 的所有底数单调递减.
 *       令反素数 s1 = ... + Ai^Bi + Ai+1^Bi+1 + ... ,
 *      存在 s2 = ... + Ai^Bi+1 + Ai+1^Bi + ...
 *      由于 Bi > Bi+1, Ai < Bi+1, 则必然会有 s2 < s1.
 *      则 s2 有可能为反素数. 而根据 推论1, 有 s1 > s2, g(s1) = g(s2), 不符合定义。
 *      所以 结论成立.
 * 事实依据1: 对于[1,2e9], 2*3*...*n, 前n个质数相乘, n最大为23.
 * 事实依据2: 对于[1,2e9], 2^n <= 2e9 的最大的n为 30.
 **/

typedef long long ll;

int max_n, res;
int primes[9] = {2,3,5,7,11,13,17,19,23};
int used_2[30] = {0};
ll dfs(int index, int value, int max_mi,int cur_mi) {
    if(index >= 9) {
        if(res < value)
            res = value;
        return value;
    }
    int n1 = 1;
    for(int i=0;i<=max_mi;i++) {
        n1 *= primes[index];
        if(i >= cur_mi) {
            if(i == 0) dfs(index+1, value, max_mi, 1);
            else {
                if(value + n1 > max_n) break;
                dfs(index+1, value+n1, max_mi, i + 1);
            }
        }


    }
}
int main() {
    int n;
    cin >> n;
    max_n = n;
    dfs(0,0,30,0);
    cout << res << endl;
    return 0;
}