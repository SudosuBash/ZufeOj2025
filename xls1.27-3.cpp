#include <bits/stdc++.h>
using namespace std;

vector<int> graph[2000001];
int school[2000001] = {0};
int used[2000001] = {0};

int st[2] = {0};
void dfs(int start) {
    used[start] = 1;
    for(int i=0;i<graph[start].size();i++) {
        int to = graph[start][i];
        if(!used[to]) {
            school[to] = !school[start]; 
            st[school[to]] += 1;
            dfs(to);
        }
    }
}
int main() {
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int ui,vi;
        cin >> ui >> vi;
        graph[ui].push_back(vi);
        graph[vi].push_back(ui);
    }
    st[school[1]] += 1;
    dfs(1);
    int minc = min(st[0],st[1]),maxc = max(st[0],st[1]);
    cout << min(minc,n-maxc) << " " << max(maxc,n-minc) << endl;
    return 0;
}