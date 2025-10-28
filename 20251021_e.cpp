/**
 Problem E:
 将整数n分成k份，且每份不能为空，任意两种划分方案不能相同(不考虑顺序)。
    例如：n=7，k=3，下面三种划分方案被认为是相同的。
    1 1 5

    1 5 1

    5 1 1
    问有多少种不同的分法。

    输入格式
    n，k (6<n<=200，2<=k<=6)
    输出格式
    一个整数，即不同的分法
    输入样例 复制
    7 3
    输出样例 复制
    4
 */
#include <iostream>
using namespace std;

int n[201];
int k;
int fanshu = 0;
void dfs(int now,int method,int target,int selected) {
    if (now > target || method > k) return;
    if (method == k && now != target) return;
    if (now == target && method != k) return;
    if (now == target && method == k) {
        fanshu+=1;
        // for (int i=1;i<=target;i++) {
        //     for (int j=0;j<n[i];j++) {
        //         cout << i << " ";
        //     }
        // }
        // cout << endl;
        return;
    }
    if (method==k-1) {
        int val = target-now;
        if (selected <= val) {
            n[val] += 1;
            dfs(now+val,method+1,target,val);
            n[val] -= 1;
        }
    } else {

        int limit = (target - now) / (k-method);
        //为什么可以这么写呢?
        //题目明确指出，1 1 5和1 5 1是一种方案
        //所以结果是递增的,假设按照题目的要求，ai>ai-1.
        //而要是超过Limit了结果就不是递增了，就有同一种方案出现了
        //limit就是最大限制，不允许超出的
        for (int i=selected;i<=limit;i++) {
            n[i] += 1;
            dfs(now+i,method+1,target,i);
            n[i] -= 1;
        }
    }

}
int main() {
    int n1;
    cin >> n1 >> k;
    dfs(0,0,n1,1);
    cout << fanshu << endl;
    return 0;
}