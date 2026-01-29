#include <bits/stdc++.h>
using namespace std;

/**
 * 树的最长直径
 *  求法: 2次dfs
 *  先假定一个节点为根节点P1，找出距离根节点直径最长的节点P2
 *  然后以P2为根节点，回溯找距离P2直径最长的节点
 */
vector<int> graph[100001];
vector<int> q[100001];
int searched[100001] = {0};

int maxS = 0;
int maxIndex = 0;
void dfs(int start,int dist) {
    if(searched[start]) return;
    searched[start] = 1;
    
    vector<int> p = graph[start];
    if(dist > maxS) {
        maxS = dist;
        maxIndex = start;
    }
    for(int i=0;i<p.size();i++) {
        dfs(p[i],dist + q[start][i]);
    }
}
int main() {
    int n;
    cin >> n;
    for(int i=1;i<n;i++) {
        int Pi,Q,Di;
        scanf("%d%d%d",&Pi,&Q,&Di);
        graph[Pi].push_back(Q);
        graph[Q].push_back(Pi);
        q[Pi].push_back(Di);
        q[Q].push_back(Di);
    }
    dfs(1,0); //找到最远的点
    memset(searched,0,sizeof(searched));
    dfs(maxIndex,0); //往回搜
    cout << (1 + maxS) * maxS / 2 + maxS * 10 << endl;
    return 0;
}