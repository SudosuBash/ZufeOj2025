#include <iostream>
#include <vector>
using namespace std;

int dp_up[101];
int dp_down[101];
int people[101];

// int statistic(int pos,int N) {
//     int res = 0;
//     for(int i=1;i<=pos;i++) {
//         if(dp_up[i] <= dp_up[i-1]) {
//             res++;
//         }
//     }
//     for(int i=N;i>=pos;i--) {
//         if(dp_down[i] <= dp_down[i+1]) {
//             res++;
//         }
//     }
//     return res;
// }

/**
 * 本来这儿是想直接统计需要去掉多少个的，但是这代码太繁琐
 * 没想到可以统计剩下的人数进而反推出该去掉的人数
 */
int statistic(int pos) {
    return dp_down[pos] + dp_up[pos]; 
}
int main() {
    int N;
    cin >> N;
    for(int i=1;i<=N;i++) {
        cin >> people[i];
    }

    dp_up[1] = 1;
    dp_up[N+1] = 100000000;
    for(int i=2;i<=N;i++) {
        if(people[i] > people[i-1]) dp_up[i] = dp_up[i-1] + 1;
        else {
            int maxc = 0;
            for(int j=1;j<i;j++) {
                if(people[j] < people[i]) maxc = max(dp_up[j],maxc);
            }
            dp_up[i] = maxc + 1;
        }
    }

    dp_down[0] = 100000000;
    dp_down[N] = 1;
    for(int i=N-1;i>0;i--) {
        if(people[i] > people[i+1]) {
            dp_down[i] = dp_down[i+1]+1;
        } else {
            int maxc = 0;
            for(int j=N;j>i;j--) {
                if(people[j] < people[i]) maxc = max(dp_down[j],maxc);
            }
            dp_down[i] = maxc + 1;
        }
    }

    int pos = N;
    int res = 2147483647;
    for(int i=1;i<=pos;i++) {
        res = min(res,N-statistic(i)+1);
        //statistic统计的结果包含pos位置两次，所以得加一个1
    }
    cout << res << endl;
    return 0;
}