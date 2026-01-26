#include <bits/stdc++.h>
using namespace std;

#define inf 0x3e3e3e3e
int graph[1010][1010] = {0};

int cost[1010] = {0}; 
//cost[i] && !used[i]:
//i属于V, 上一个连到i的点属于U, 所以只需要遍历这些就好了.
//而cost[i]存储的是U中的点到V的最小值, 所以遍历U V找最小边其实等价于遍历cost

/**
 * Prim 算法:
 *  1.维护一个集合U, 集合V, 初始将第1个点加入U, 其余点加入V.
 *  2.然后遍历U中的点和V中的点的每一条边, 寻找最小权值的边, 对应点P1->P2.
 *  3.找到之后, 将P1从V中弹出, 加入U中.
 *  4.重复执行2,3, 直到len(V) = 0.
 */
int used[1010] = {0}; //第i个点被走过了吗?
int n,m;
//n: 点数目
//m: 候选路径
int prim() {

    int point,sum=0,cnt;
    used[1] = 1; 
    //初始状态: 第一个点被用过
    point = 1; 
    //目前正在第1个点
    cnt = 1; //计数

    //cost[i]是最短距离
    for(int i=1;i<=n;i++) {
        cost[i] = graph[1][i]; 
    }

    while(cnt < n) { //cnt: 找第i个点
        int cmin = inf;
        //每次从"一端在U中，一端在V中"的所有边里面，选择权值最小的那条边
        //其实就是找cost的每一个元素, 原因见上
        for(int i=1;i<=n;i++) {
            if(!used[i] && cmin > cost[i]) {
                cmin = cost[i]; //要加入U集合的下一个点的花费
                point = i; //加入U集合的下一个点
            }
        }

        if(cmin == inf) {
            return -1; 
            //cnt<n的情况下又找不到下一个点，那就是找不到了
        }
        sum+=cmin; //U集合的最值
        used[point] = 1; //这个操作就是加入U集合
        /**
         * 现在，需要更新cost数组,也就是所有U到V的最短路径的最小值
         * cost[P1] = P2, P1属于V, P2属于U
         * 而现在U新加入一个点X, 那么只需要判断新加入的这个点X到P1的距离
         * 和P2到P1的距离, 其实就是U->V的最短距离
        */
        for(int i=1;i<=n;i++) {
            if(!used[i] && graph[point][i] < cost[i]) {
                cost[i] = graph[point][i]; //更新最短距离
            }
        }
        //cnt只用于计数，没别的意思
        cnt++;
    }
    return sum;
}
//无向图
int main() {
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i==j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = graph[j][i] = inf;
            }
        }
    }

    for(int i=1;i<=m;i++) {
        int a,b,v;
        cin >> a >> b >> v;
        graph[a][b] = v;
        graph[b][a] = v;
    }
    cout << prim();
    return 0;

}