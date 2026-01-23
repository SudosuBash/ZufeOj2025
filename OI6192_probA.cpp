#include <bits/stdc++.h>
using namespace std;


int main() {
    /**
     * 输入首先在第一行给出 3 个正整数
     * 分别是彩虹瓶的颜色数量 N（1<N≤103）、临时货架的容量 M（<N）、以及需要判断的发货顺序的数量 K。
     */

    int N,M,K;
    cin >> N >> M >> K;

    for(int i=0;i<K;i++) {
        stack<int> s;
        int succ = 1;
        int top = 1;  //top是彩虹瓶的top
        for(int i=0;i<N;i++) {
            
            int n;
            cin >> n; 
            if(n == top) { //可以配对
                top+=1;
                while(!s.empty() && (n = s.top()) == top) { //top+1是编号
                    s.pop();
                    top+=1;
                }
            } else { //不可配对
                s.push(n);
                if(s.size() > M) {
                    succ = 0;
                    // break;
                    // 整无语了: cin要输入完, 不能输入到一半啊-
                }
            }
        }
        if(succ == 0 || !s.empty()) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}