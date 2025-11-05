// 题目类型: 鱼塘类
// 思路:
// 1.先获得每个鱼塘可以钓的钓鱼时间，同时获得可以钓的鱼塘
// 2.以每个鱼塘的钓鱼时间为基准，对最多走到该鱼塘的情况做贪心算法，算出最大可钓的鱼(每次都选当前可以钓的最大的鱼)
// 3.然后选出最大的时间
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
    objekt obj[100001];
    int N;
    cin >> N;
    for(int i=0;i<N;i++) {
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
    int limit_xiabiao = N; //不是0!
    //不是N-1
    for(int i=1;i<N;i++) {
        obj[i].rest_time = obj[i-1].rest_time - obj[i-1].next_time;
        if(obj[i].rest_time < 0) {
            limit_xiabiao = i;
            break;
        }
    } //计算枚举边界
    int resmax = 0;
    for(int i=0;i<limit_xiabiao;i++) { //枚举所有可能出现的钓鱼剩余时间
        int res = 0;//
        priority_queue<pair<int,int>> m1;
        int rest_time = obj[i].rest_time;
        for (int j=0;j<i+1;j++) {
            pair<int,int> p1;
            p1.first = obj[j].rest; //first: 该鱼塘剩余的鱼的数量是多少?
            p1.second = j; //second: 哪个鱼塘?
            m1.push(p1); //放入优先队列
        } //初始化该情境下的优先队列
        //rest_time>0: 还有钓鱼时间
        //m1.empty: 鱼塘还有鱼
        while (rest_time > 0 && !m1.empty()) {
            pair<int,int> p1 = m1.top();
            int index = p1.second; //哪个鱼塘?
            res += p1.first; //钓到的鱼
            m1.pop();
            if (p1.first - obj[index].sub> 0) { //该鱼塘还有鱼?
                p1.first -= obj[index].sub; //更新鱼的数量
                m1.push(p1); //重新加回去，还得参与运算
            }
            rest_time -= 1;//最后别忘了减时间
        }
        resmax = max(resmax, res);
    }
    cout << resmax << endl;
    return 0;
}