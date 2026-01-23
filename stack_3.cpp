#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,M,K;
    cin >> N >> M >> K;
    for(int i=0;i<K;i++) {
        stack<int> jiazi;
        string stat = "YES";
        int tmp1 = 1;
        for(int j=0;j<N;j++) {
            int n;
            cin >> n;
            if(n != tmp1) {
                jiazi.push(n);
                if(jiazi.size() > M) stat = "NO";
            } else {
                tmp1+=1; //颜色+1，略过tmp1
                while(!jiazi.empty()) {
                    n = jiazi.top(); //当前货物=架子顶部的货物
                    if(n!=tmp1) break; //不一样的话就不行了
                    tmp1+=1;//颜色+1
                    jiazi.pop(); //弹出栈顶
                }
            }
        }
        if(!jiazi.empty()) stat = "NO";
        cout << stat << endl;
    }
    
    return 0;
}