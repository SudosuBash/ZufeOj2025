#include <bits/stdc++.h>
using namespace std;

int collection[1000001] = {0};
//collection对应的部落
int buluo[1000001] = {0};
//部落对应的根人数
int cfind(int x) {
    // if(x == buluo[collection[x]]) return x;
    // collection[x] = cfind(collection[x]);
    int n=x;
    
    while(n != buluo[collection[n]]) 
        n=collection[n];
    collection[x]=collection[n];
    return n;
}
void solve(int n1,int n2) {
    memset(collection+1,0,(n1)*sizeof(int));
    memset(buluo+1,0,(n1)*sizeof(int));
    for(int i=1;i<=n1;i++) {
        collection[i] = i;
        buluo[i] = i;
    }
    for(int i=0;i<n2;i++) {
        int op;
        cin >> op;
        int src1,src2;
        if(op == 4) {
            cin >> src1;
        } else {
            cin >> src1 >> src2;
        }
        
        switch(op) {
            case 1: {
                int rl = cfind(src1);
                int rr = cfind(src2);
                collection[rr] = rl;
                break;
            }
            case 2: {
                int rr = cfind(src2);
                collection[src1] = rr;
                break;
            }
            case 3: {
                //src1部落1 src2部落2
                int prevl = buluo[src1]; //部落1
                int prevr = buluo[src2]; //部落2

                buluo[src1] = prevr;
                buluo[src2] = prevl;
                collection[prevl] = src2;
                collection[prevr] = src1;
                break;
            }
            case 4: {
                cout << collection[cfind(src1)] << endl;
                break;
            }
        }
    }

}
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int group;
    cin >> group;
    for(int i=0;i<group;i++) {
        int n1,n2;
        cin>>n1>>n2;
        solve(n1,n2);
    }
    return 0;
}