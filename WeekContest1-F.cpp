/**
题目描述
单词接龙是一个与我们经常玩的成语接龙相类似的游戏，现在我们已知一组单词，且给定一个开头的字母，要求出以这个字母开头的最长的“龙”（每个单词都最多在“龙”中出现两次），在两个单词相连时，其重合部分合为一部分，例如beast和astonish，如果接成一条龙则变为beastonish，另外相邻的两部分不能存在包含关系，例如at和atide间不能相连。


输入格式
每个测试文件只包含一组测试数据，每组输入的第一行为一个单独的整数n（n<=20）表示单词数，以下n行每行有一个单词，输入的最后一行为一个单个字符，表示“龙”开头的字母。你可以假定以此字母开头的“龙”一定存在。


输出格式
对于每组输入数据，输出以此字母开头的最长的“龙”的长度。
下面的测试样例最后连成的“龙”为atoucheatactactouchoose。
*/
#include <bits/stdc++.h>

using namespace std;

string strs[1001] = {""};
int used[1001] = {0};
int smax = 0;
string smaxString;

int check(string c,string c1) {
    map<string, int> mp;
    string s;
    for (int i=0;i<c1.length();i++) {
        s+=c1[i];
        mp[s] = 1;
    }
    s="";
    int maxLength = -1;
    for (int i=c.length()-1;i>=0;i--) {
        s=c[i]+s;
        if (mp[s] == 1) {
            maxLength = c.length()-i;
            break; //当初以为重叠后字符串必须要最大，特地把break去掉了
            //得知真正题目意图的我：🤡
        }
    }
    return maxLength;
}
void dfs(string c,int n) {
    if (c.size() > smax) {
        smax = c.size();
        smaxString = c;
    }
    for (int i=0;i<n;i++) {
        int len = check(c,strs[i]);
        if (used[i] < 2 && len != -1 &&
            len != c.length() && len!=strs[i].length()) {
            used[i] += 1;
            string news = c + strs[i].substr(len);
            dfs(news,n);
            used[i] -=1 ;
        }
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        strs[i] = s;
    }
    char c;
    cin >> c;
    for (int i=0;i<n;i++) {
        if (strs[i][0] == c) {
            used[i] += 1;
            dfs(strs[i],n);
            used[i] -= 1;
        }

    }
    cout << smax << endl;
    return 0;
}