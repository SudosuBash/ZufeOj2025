#include <bits/stdc++.h>
using namespace std;
const int maxc = 1e5+1;
vector<int> graph[maxc];

queue<int> elements;
int used[1001] = {0};
void bfs() {
    elements.push(1);
    while(!elements.empty()) {
        int c = elements.front();
        elements.pop();
        for(int i=0;i<graph[c].size();i++) {
            int v = graph[c][i];
            
        }
    }

}
int main() {
    int N;
    cin >> N;
    for(int i=0;i<N;i++) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}