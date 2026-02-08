#include <bits/stdc++.h>
using namespace std;

int cp[1001] = {0};
int maxres = 0;
void solve(int start,int N) {
    queue<int> q;
    for(int i=start;i<=N;i++) {
        q.push(cp[i]);
    }
    for(int i=1;i<start;i++) {
        q.push(cp[i]);
    }
    int cnt = 1, res = 0;
    while(!q.empty()) {
        int f = q.front();
        int st = q.size();
        if(cnt == f) {
            res+=f;
            cnt = 1;
            q.pop();
            continue;
        } else {
            q.push(f);
        }
        if(cnt == st) {
            break;
        }
        cnt++;
        q.pop();
        
    }
    maxres = max(res,maxres);

}
int main() {
    int N;
    cin >> N;
    for(int i=1;i<=N;i++) {
        cin >> cp[i];
    }

    for(int i=1;i<=N;i++) {
        solve(i,N);
    }

    cout << maxres << endl;
    return 0;
}