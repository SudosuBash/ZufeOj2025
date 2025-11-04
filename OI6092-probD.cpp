/**
 * 
题目描述
党的十八大提出， 倡导富强、 民主、 文明、 和谐， 倡导自由、 平等、 公正、 法治，倡导爱国、 敬业、 诚信、 友善， 积极培育和践行社会主义核心价值观。 富强、 民主、 文明、 和谐是国家层面的价值目标， 自由、 平等、 公正、 法治是社会层面的价值取向， 爱国、 敬业、 诚信、 友善是公民个人层面的价值准则， 这 24 个字是社会主义核心价值观的基本内容。
但是在互联网上， 会有一些不文明的人发送不文明的言论。 我们的目的， 就是要自动过滤并且识别这些言论。
给出一个字符串 S， 表示那些可能不文明的言论。 再给出一个字典 T， 包含了 n条违规的用语， T[1], T[2], …, T[n]。 要在 S 中添加最少的*， 使得只要违规用语T[i]在 S 中出现， 就得在每个 T[i]的字符之间添加*。
比如说 S=aaabbssss， T[1]=abb， T[2]=bbss。 那么最后的符合规定的 S’就为aaa*b*b*s*sss。 其中 abb 在第 3 到第 5 个字符之间出现， bbss 在第 4 到第 7个字符出现。
数据保证字符串 S 不包括字符‘*’ ， 且 T[i]的长度一定大于 1。其中|S|≤1000， n≤10， 1<|T[i]| ≤100； |S|表示 S 字符串的长度， |T[i]|表示 T[i]字符串的长度。


输入格式

一共有 n+2 行， 第一行为 S。 第二行为 n（一共有几个违规用语） 。 接下来 n 行每行一个字符串表示违规用语 T[i]

对 100%的数据， |S|≤1000， n≤10， 1<|T[i]| ≤100 
输出格式
共一行， 即合格的字符串 S’。
输入样例 复制

aaabbssss
2
abb
bbss

输出样例 复制

aaa*b*b*s*sss
 */
#include <bits/stdc++.h>
#include <cctype>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> res;
    vector<string> res2;
    for(int i=0;i<n;i++) {
        string a;
        cin >> a;
        res.push_back(a);
    }

    int i-3nsert[100001] = {0};
    for(int i=0;i<s.length();i++) {
        char c = s[i];
        for(int j=0;j<res.size();j++) {
            string s2 = res[j];
            int weiguiciLeng = s2.length();
            int targetLength = i+1;
            
            if(targetLength >= weiguiciLeng) {
                string tmp1 = s.substr(targetLength-weiguiciLeng, weiguiciLeng);
                if(tmp1 == s2) {
                    for(int s=targetLength-weiguiciLeng;s<targetLength-1;s++) {
                        insert[s] = 1; 
                    }
                }

            }
        }
    }

    for(int i=0;i<s.length();i++) {
        cout << s[i];
        if(insert[i]) cout << "*";
    }

    return 0;
}