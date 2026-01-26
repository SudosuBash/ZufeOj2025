#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef struct {
    ll b; //哪台计算机?
    ll end_time;
    ll suanli;
} task_t;
int suanli[200002] = {0};
typedef struct {
    ll suanli;
} obj_t;
queue<task_t> tasks;

int main() {
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        scanf("%d",&suanli[i]);
        // cin >> suanli[i];
    }
    for(int i=1;i<=m;i++) {
        ll a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        // cin >> a >> b >> c >> d;
        /** a: 时间 b: 计算机编号 c: 耗时 d: 算力消耗 */
        
        while(!tasks.empty()) {
            task_t t = tasks.front();
            if(t.end_time > a) break;
            
            tasks.pop();
            suanli[t.b] += t.suanli;
        }
        task_t t1 = {
            .b = b,
            .end_time = a + c,
            .suanli = d
        };
        if(suanli[b] >= d) {
            tasks.push(t1);
            suanli[b] -= d;
            cout << suanli[b] << endl;
        } else {
            cout << "-1" << endl;
        }
    }
}