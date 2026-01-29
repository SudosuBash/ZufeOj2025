#include <bits/stdc++.h>
using namespace std;

/**
 * SPFA计算图中，某个点到另一个点的最小权值
 *  关于为什么还有
 */
typedef struct {
    int to;
    int val;
} obj_t;
vector<obj_t> graph[10001];
queue<int> qo;
int val[10001] = {0};
int in_que[10001] = {0}; //在队列里面吗?

void spfa(int st,int ed) {
    memset(val,0x3f3f,sizeof(val));
    val[st] = 0; //从这个点开始
    in_que[st] = 1;
    qo.push(st);
    while(!qo.empty()) {
        int valc = qo.front();
        qo.pop();

        in_que[valc] = 0;

        for(int i=0;i<graph[valc].size();i++) {
            int v = graph[valc][i].to;
            if(graph[valc][i].val + val[valc] < val[v]) {
                //无向图的话，这部分是不会导致重复的
                //因为要是出现a->b->c->b的话，那么c->b的这步骤是不满足 graph[valc][i].val + val[valc] < val[v] 的

                val[v] = graph[valc][i].val + val[valc];
                if(in_que[v] == 0) {
                    qo.push(v);
                    in_que[v] = 1; 
                    //一旦最小值有更新，那么就需要重新处理点
                    //但是要是点本身就在队列中，那么本身就可以被队列处理，所以没有必要再加进队列了
                }
            }
        }
    }
    cout << val[ed] << endl;
}
int main() {
    int T,C,Ts,Te;
    cin >> T >> C >> Ts >> Te;
    /**
     * 始点和终点一共有 T 个城镇，为了方便标号为 1 到 T。
     * 包含 C 条直接连接 2 个城镇的道路。
     * 起始的城镇 Ts 到终点的城镇 Te 
     */
    for(int i=0;i<C;i++) {
        int Rs,Re,Ci;
        cin >> Rs >> Re >> Ci;
        //每条道路由道路的起点 Rs，终点 Re 和花费 Ci 组成。
        graph[Rs].push_back({Re,Ci});
        graph[Re].push_back({Rs,Ci});
    }
    spfa(Ts,Te);
    return 0;
    //求从起始的城镇 Ts 到终点的城镇 Te 最小的总费用。 

}