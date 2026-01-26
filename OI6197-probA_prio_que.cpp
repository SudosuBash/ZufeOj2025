/**
 * Dijkstra算法 - 优先队列版本
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int dis; //距离
    int num; //节点编号
} node;

int disc[105]; //存储节点到每个节点的距离
vector<int> graph[105], c[105];
//graph: 图信息, c: 权值信息
priority_queue<node> que;
//que是存储处理的节点, 注意, 待处理的节点
bool operator<(const node &a, const node &b) { //重载<运算符
    return a.dis > b.dis;
    //从小到大排序
}

void dijistra(int u,int v) {
    node tmp = {
        .dis = 0,
        .num = u
    };
    que.push(tmp);

    memset(disc,0x3f3f,sizeof(disc));
    disc[u] = 0;

    while(!que.empty()) {
        node fro = que.top(); //选距离最小的节点进行处理
        que.pop();

        //为什么是 '!=' 呢? 
        /**
         * 优先队列所有后面入队的值都会比这个小
         * 在入队的时候老早把对应的disc给改了
         * 所以 '!=' 也可以
         */
        if(fro.dis != disc[fro.num]) 
            continue;

        for(int index = 0;index < graph[fro.num].size();index++) {
            int to = graph[fro.num][index]; 
            //to: 下一个节点的值
            if(c[index][to] + disc[fro.num] < disc[to]) { 
                // c[index][to]: 当前路径权值
                // disc[fro.num]: 已经处理过的权值
                disc[to] = min(c[index][to] + disc[fro.num], disc[to]);
                que.push(node{disc[to],to});   
                
            }
        }
    }
}
int main() {
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int u,v,val;
        cin >> u >> v >> val;
        graph[u].push_back(v);
        c[u].push_back(val);
    }
}