/**
 * 题目:
 *  给定一个数组s,长度最大10^5，s[i]不超过10^6.现在定义合并相邻两个s元素的操作为A.
 *  例如s=[1,2,3,4,5]，合并s[1] s[2]后，它变成[1,5,4,5].
 *  求进行多少次A，可以让这个数组的每个元素相等。
 * 思路:
 *  题目转化为最多可以分为多少个值相等的段
 *  也就是说，假设数组总和为S，每段的值为K，最多分为S/K段.
 *  由上述描述可知，K必须被S整除。
 *  由于段最小值也是比数组最大值大的，所以令数组最大值为H=max(s)
 *  也就是对H~S进行枚举，找出所有的能被S整除的数字，组成一个数组，那个数组就是段长度。
 *  然后通过对原数组进行尝试合并操作,如果能合并的话就是 n-S/K 次操作。
 */
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


bool check(vector<int> v,int n) {
    int l = 0;
    for(int i : v) {
        l += i;
        if(l == n) {
            l = 0;
        }
        if(l > n) {
            return false; //无法合并
        }
    }
    return l == 0; //最后一个是不是0?否则照样无法合并
}
int main() {
    //想过dp和贪心，但是dp貌似后一个的状态和前一个没关系
    //贪心的话排序之后也搞不定
    //也想过dfs，但是这数据规模一看就超时
    //只能问ai给点提示

    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        int n1;
        cin >> n1;
        //第一步:预处理
        int aimax = 0,aisum = 0; //最大数和总和
        vector<int> v;
        for(int j=0;j<n1;j++) {
            
            int ai;
            cin >> ai;
            aimax = max(ai,aimax);
            aisum += ai;//总和计算
            v.push_back(ai);
        }
        //构建好数组v
        //第二步:寻找最大数(找好了)
        //第三步:寻找因子(二分)
        if(aimax == 0) { //0特殊处理
            cout << 0 << endl;
            continue;
        }
        int maxCount = aisum / aimax;
        //数组最大可以合成的长度是maxCount(总和/最大数，因为是相邻合并)
        //最小可以合成的长度是1
        int l = maxCount;
        int r = 1;
        int now = l;
        for(now=l;now>=r;now--) {
            if(aisum % now != 0) continue; //不可能出现
            if(check(v,aisum / now)) { //找到了
                break;
            }
        }
        cout << v.size() - now << endl;
    }
    return 0;
}