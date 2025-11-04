/**
 * 
题目描述

有N个鱼塘排成一排（N<100），每个鱼塘中有一定数量的鱼，例如：N=5时，如下表：



即：在第1个鱼塘中钓鱼第1分钟内可钓到10条鱼，第2分钟内只能钓到8条鱼，……，第5分钟以后再也钓不到鱼了。从第1个鱼塘到第2个鱼塘需要3分钟，从第2个鱼塘到第3个鱼塘需要5分钟，……

给出一个截止时间T(T<1000)，设计一个钓鱼方案，从第1个鱼塘出发，希望能钓到最多的鱼。

假设能钓到鱼的数量仅和已钓鱼的次数有关，且每次钓鱼的时间都是整数分钟。



https://www.bilibili.com/video/BV17FBiYPEUD/
输入格式

共5行，分别表示：

第1行为N；

第2行为第1分钟各个鱼塘能钓到的鱼的数量，每个数据之间用一空格隔开；

第3行为每过1分钟各个鱼塘钓鱼数的减少量，每个数据之间用一空格隔开；

第4行为当前鱼塘到下一个相邻鱼塘需要的时间；

第5行为截止时间T。
输出格式
一个整数（不超过231−1231−1），表示你的方案能钓到的最多的鱼。
输入样例 复制

5
10 14 20 16 9
2 4 6 5 3
3 5 4 4
14

输出样例 复制

76
 */
#include <bits/stdc++.h>
#include <queue>


using namespace std;

typedef struct {
    int rest; //剩余鱼
    int sub; //减少的鱼量
    int next_time = 0; //到下一个鱼塘的时间
    int rest_time = 0; //上个鱼塘到这个鱼塘总花费时间
} objekt;
int main() {

    priority_queue<pair<int,int>> m1;

    objekt obj[100001];
    int N;
    cin >> N;
    for(int i=0;i<N;i++) {
        // pair<int,int> p;
        // cin >> p.first; // p.first 鱼塘数量
        // p.second = i;
        // m1.push(p);
        //         obj[i].rest = p.first;
        cin >> obj[i].rest;
    }

    for(int i=0;i<N;i++) {
        cin >> obj[i].sub;
    }
    for(int i=0;i<N-1;i++) {
        cin >> obj[i].next_time;
    }

    int limit_time;
    cin >> limit_time;

    obj[0].rest_time = limit_time;
    int limit_xiabiao = 0;
    for(int i=1;i<N;i++) {
        obj[i].rest_time = obj[i-1].rest_time - obj[i-1].next_time;
        if(obj[i].rest_time < 0) {
            limit_xiabiao = i;
            break;
        }
    }

    for(int i=0;i<limit_xiabiao;i++) {
        pair<int,int> p;
        p.first = obj[i].rest;
        p.second = i;
        m1.push(p);
    }

    int res = 0;
    while() {
        pair<int,int> out = m1.top();
        out.first -= obj[0].sub;
        res += obj[0].sub;
        if(out.first <= 0) m1.pop();

    }

    return 0;
}