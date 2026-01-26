#include <bits/stdc++.h>
using namespace std;
vector<int> graph[1001];
int ys[1001] = {0};
int tar[1001] = {0};

void judge(int K,int V,int E) {
    memset(tar,0,sizeof(tar));
    int js = 0;
    for(int j=1;j<=V;j++) {
        cin >> ys[j];
        if(tar[ys[j]] == 0) {
            tar[ys[j]] = 1;
            js += 1;
        }
    }

    if(js != K) {
        cout << "No" << endl;
        return;
    }

    for(int i=1;i<=E;i++) {
        for(int j:graph[i]) {
            if(ys[j] == ys[i]) {
                cout << "No" << endl;
                return;
            }
        }
        
    }
    cout << "Yes" << endl;
}
int main() {
    int V,E,K;
    cin >> V >> E >> K;
    for(int i=0;i<E;i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        // graph[v].push_back(u);
    }
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        judge(K,V,E);
       
    }
    

    return 0;
}