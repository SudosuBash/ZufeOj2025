#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int time; //到达时间
    vector<int> v; //国籍
} solv_t;


queue<solv_t> sol;
int nation[300001] = {0}; //Nation
int main() {
    int n;
    cin >> n;
    //n艘船
    int diffNation = 0;
    for(int i=0;i<n;i++) {
        solv_t s;
        int ki;
        scanf("%d%d",&s.time,&ki);
        //我这辈子，最恨的就是cin
        // cin >> s.time;
        // cin >> ki;
        s.v = vector<int>();
        for(int j=0;j<ki;j++) {
            int nat;
            scanf("%d",&nat);
            // cin >> nat;
            s.v.push_back(nat);
            if(nation[nat] == 0) {
                diffNation += 1;
            }
            nation[nat] += 1;
        }
        sol.push(s);
        while(!sol.empty()) {
            solv_t sol_o = sol.front();
            if(s.time - sol_o.time < 86400) 
                break;
            sol.pop();
            for(int i=0;i<sol_o.v.size();i++) {
                nation[sol_o.v[i]] -= 1;
                if(nation[sol_o.v[i]] == 0) {
                    diffNation -= 1;
                }
            }
        }
        printf("%d\n",diffNation);
        // cout << diffNation << endl;

    }
    return 0;
}