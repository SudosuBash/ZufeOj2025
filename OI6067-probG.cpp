/**
题目描述
今天是阴历七月初五，acm队员zb的生日。zb正在和C小加、never在武汉集训。他想给这两位兄弟买点什么庆祝生日，经过调查，zb发现C小加和never都很喜欢吃西瓜，而且一吃就是一堆的那种，zb立刻下定决心买了一堆西瓜。当他准备把西瓜送给C小加和never的时候，遇到了一个难题，never和C小加不在一块住，只能把西瓜分成两堆给他们，为了对每个人都公平，他想让两堆的重量之差最小。每个西瓜的重量已知，你能帮帮他么？
输入格式
多组测试数据（<=1500）。数据以EOF结尾
第一行输入西瓜数量N (1 ≤ N ≤ 20)
第二行有N个数，W1, …, Wn (1 ≤ Wi ≤ 10000)分别代表每个西瓜的重量
输出格式
输出分成两堆后的质量差
*/
#include <bits/stdc++.h>
using namespace std;

// int used[1001] = {0};
int weight[1001] = {0};

int minValue = 2147483647;
/*改进: 优化剪枝操作
 不用Used数组，基于索引
 道理和used数组其实是一样的，全都是搜索(0选/不选后推到1选/不选，进而数学归纳法推到n选/不选)
 但是这样能省去大量的无效的for循环，所以是可行的
*/
void dfs(int n,int weight1,int maxn,int sumWeight,int now) {
    int weight2 = sumWeight - weight1;
    if (minValue > abs(weight2 - weight1)) {
        minValue = abs(weight2 - weight1);
    }
    if (now >= maxn) return;
    dfs(n+1,weight1,maxn,sumWeight,now+1); //选择西瓜
    dfs(n+1,weight1+weight[now],maxn,sumWeight,now+1); //不选择西瓜
    /**
     * for(int i=0;i<maxn;i++) {
     *     if(!used[i]) {
     *         used[i] = 1;
     *         dfs(n,weight1+weight[i], maxn, sumWeight, now);
     *         used[i] = 0;
     *     }
     * }
     */
}

int main() {
    int n;
    while (cin>>n) {
        minValue = 2147483647;
        long sumWeight = 0;
        for (int i=0;i<n;i++) {
            cin >> weight[i];
            sumWeight += weight[i];
        }
        sort(weight,weight+n);
        dfs(0,0,n,sumWeight,0);
        cout << minValue << endl;
    }
    return 0;
}