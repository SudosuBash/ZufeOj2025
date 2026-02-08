#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int main() {   
    int T;
    cin >> T;
    for(int i=1;i<=T;i++) {
        int n,k;
        //n: 序列数量 k: 万能方块
        q = queue<int>();
        cin >> n >> k;
        vector<int> v;

        for(int j=1;j<=n;j++) {
            int ai;
            cin >> ai;
            v.push_back(ai);
        }
        for(int j=v.size()-1;j>=0;j--) {
            q.push(v[j]);
        }
        int proced = 0;
        int cmax = -1e6;
        while(proced <= n) {
            int c = q.front(); //最前面
            q.pop();
            q.push(k);
            cmax = max(cmax,c+k);
            
            
            k=c;
            proced+=1;
        }
        cout << cmax << endl;
    }
}