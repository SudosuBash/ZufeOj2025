/**
*小 A 有一个由 n个小写字母组成的字符串s 。他希望将 s 划分为若干个子串，使得子串中每个字母至多出现一次。 例如，对于字符串 street 来说， str + e + e + t 是满足条件的划分；而 s + tree + t 不是，因为子串 tree 中 e 出现了两次。

额外地，小 A 还给出了价值 a1,a2,..,an，表示划分后长度为i 的子串价值为ai 。小 A 希望最大化划分后得到的子 串价值之和。你能帮他求出划分后子串价值之和的最大值吗？


输入格式
第一行，一个正整数 n，表示字符串的长度。
第二行，一个包含 n个小写字母的字符串 s。
第三行， n个正整数 a1,a2,...,an，表示不同长度的子串价值。
n<=105    1<=ai<=109
输出格式
输出 一行，一个整数，表示划分后子串价值之和的最大值


输入
8
blossoms
1 1 2 3 5 8 13 21
输出
8
*/
#include <bits/stdc++.h>

using namespace std;

char str[1001] = {0};
int value[1001] = {0};
void dfs() {

}
int main() {
    int stringLen;
    cin >> stringLen;
    for (int i=0;i<stringLen;i++) {
        cin >> str[i];
    }
    for (int i=0;i<stringLen;i++) {
        cin >> value[i];
    }
    return 0;
}