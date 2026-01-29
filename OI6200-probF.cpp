#include <bits/stdc++.h>
using namespace std;
//拆最多2个
typedef struct {
    int to; //指向哪儿?
    int next; //下一条边?
    int value; //权值?
} obj_t;

typedef struct {
    int val; //权值
    int node_num; //节点编号
} node_t;

int head[1001] = {0};
obj_t nodes[1001] = {0};
int dis[1001] = {0}; //到每个节点的距离
int c_index = 0;
//链式前向星算法构建链表

priority_queue<node_t> proc;
void add(int u,int v, int val) {
    obj_t node = {
        .next = head[u],
        .to = v,
        .value = val
    };
    head[u] = c_index; 
    nodes[c_index++] = node;
}
bool operator<(const node_t& n1,const node_t& n2) {
    return n1.val > n2.val;
}
void dijkstra(int all) {
    node_t n = {
        .node_num = 1,
        .val = 0
    };
    proc.push(n);
    while(!proc.empty()) {
        node_t front = proc.top();
        proc.pop();

        if(front.val > dis[front.node_num]) 
            continue;
        //后续已经找到更小的数了，所以该数需要在后续处理，而不是当前循环
        //当前循环的值已经作废了
        int idx = head[front.node_num];
        //找该节点对应子节点的最小权值
        while(idx!=0) {
            obj_t o = nodes[idx];
            //front.val: 前一个的累加权值
            //o.value: 当前权值
            //dis[o.to]: 当前节点最小权值
            //更小的话就加入边
            if(front.val + o.value < dis[o.to]) {
                dis[o.to] = front.val + o.value;
                //当前节点最小权值不是最小的，那么需要对下一个节点进行处理
                proc.push(node_t{dis[o.to],o.to});
            }
            idx = o.next;
        }
    }
}
int main() {
    int n,m;
    cin >> n >> m;
    memset(dis,0x3f3f,sizeof(dis));
    for(int i=0;i<m;i++) {
        int a,b,c,d;
        /* a,b之间有一段长度为c的道路，d=0没有限高杆 */
        cin >> a >> b >> c >> d;
        add(a,b,c);
        // if(d == 0) {
        //     //构建分层图
            
        //     add(b,a,c);
        //     add(a+n,b+n,c);
        //     add(b+n,a+n,c);
        //     add(a+2*n,b+2*n,c);
        //     add(b+2*n,a+2*n,c);
        // } else {
        //     //分层图之间连起来
        //     add(a,b+n,c);
        //     add(b+n,a,c);
        //     add(a+n,b+2*n,c);
        //     add(b+2*n,a+n,c);
        // }
    }

    dijkstra(n);
    // cout << dis[3*n] - dis[n-1] << endl;
}