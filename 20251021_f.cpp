#include <bits/stdc++.h>
using namespace std;

int used[101];
int valUsed[1001];
int method = 0;
vector<int> c;
void dfs(int currentIndex,int now,int valid) {
    int sol = now;

    if (!valUsed[sol] && valid) {
        method+=1;
        valUsed[sol] = 1;
        // cout << sol << endl;
    }
    for (int i = currentIndex; i < c.size(); i++) {
        if (!used[i]) {
            used[i] = 1;
            dfs(i+1,now+c[i],1);
            used[i] = 0;
        }
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        c.push_back(tmp);
    }
    sort(c.begin(), c.end());
    dfs(0,0,0);
    cout << method << endl;
    return 0;
}