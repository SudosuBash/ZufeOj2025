#include <bits/stdc++.h>
using namespace std;


// typedef struct {
//     int from;
//     int to;
// } obj_t;
queue<int> qo;
vector<int> graph[1001];

int rd[10001] = {0};
int searched[10001] = {0};
void search(int N) {
    for(int i=1;i<=N;i++) {
        if(rd[i] == 0)
            qo.push(i);
    }
    while(!qo.empty()) {
        int c = qo.front();
        qo.pop();
        cout << c << " ";
        for(int i=0;i<graph[c].size();i++) {
            int to = graph[c][i];
            rd[to] -= 1;
            if(rd[to] == 0) {
                qo.push(to);
            }
        }
    }


}
int main() {
    int N;
    cin >> N;
    for(int i=1;i<=N;i++) {
        int num;
        cin >> num;
        while(num!=0) {
            graph[i].push_back(num);
            rd[num] += 1;
            cin >> num;
        }
    }
    search(N);
    return 0;
}