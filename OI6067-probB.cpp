/*
 *
题目描述
排列与组合是常用的数学方法，其中组合就是从n个元素中抽出r个元素(不分顺序且r≤n)，我们可以简单地将n个元素理解为自然数1，2，…，n，从中任取r个数。

现要求你用递归的方法输出所有组合。

例如n＝5，r＝3，所有组合为：

1 2 3   1 2 4   1 2 5   1 3 4   1 3 5   1 4 5   2 3 4   2 3 5   2 4 5   3 4 5




视频 讲解：https://www.ixigua.com/7203739026300502566

输入格式
一行两个自然数n、r(1<n<21，1≤r≤n)。
输出格式
所有的组合，每一个组合占一行且其中的元素按由小到大的顺序排列，每个元素间用一个空格隔开，所有的组合也按字典顺序。
 */

#include <bits/stdc++.h>

using namespace std;

int k,n;
int used[1001];
void dfs(string s,int n1,int current) {
    if(n1 == n) {
        cout << s << endl;
        return;
    }
    if (current > k) return;
    dfs(s + to_string(current) + " ", n1 + 1, current + 1);
    dfs(s, n1, current + 1);
// 基於索引
    // for(int i=current+1;i<=k;i++) {
    //     if(!used[i]) {
    //         used[i] = 1;
    //         dfs(s+to_string(i)+" ",n1+1,i);
    //         used[i] = 0;
    //     }
    // }
}
int main() {
    cin >> k;
    cin >> n;
    dfs("",0,1);
    return 0;
}