#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
int rd[10001] = {0};

int search(int n) {
    queue<int> qo;
    int proced = 0;
    for(int i=1;i<=n;i++) {
        if(rd[i] == 0) {
            qo.push(i);
            proced += 1;
        }
    }
    int flag = 1;
    //qo是待处理的队列，要是待处理的队列有一堆的话证明可以先出队
    while(!qo.empty()) {
        int front = qo.front();
        qo.pop();
        if(!qo.empty()) flag = 2; //精髓
        //问: 为什么不能直接return 2?
        for(int i=0;i<graph[front].size();i++) {
            int to = graph[front][i];
            rd[to] -= 1;
            if(rd[to] == 0) {
                proced += 1;
                qo.push(to);
            }
        }
    }
    if(proced < n) {
        flag = 0;
    }
    //就没处理完
    return flag;
}
int main() {
    int n,m;
    while(cin >> n >> m) {
        for(int i=1;i<=n;i++) {
            graph[i].clear();
        }
        for(int i=1;i<=m;i++) {
            int d,u;
            cin >> d >> u;
            graph[d].push_back(u);
            rd[u] += 1;
        }
        cout << search(n) << endl;
        memset(rd,0,sizeof(rd));
    }

    return 0;
}