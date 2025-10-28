#include <bits/stdc++.h>

using namespace std;

int minTime = 2147483647;
int arr[1001][1001] = {0};
int used[1001]={0};
void dfs(int n,int time, int limit) {
    if (n==limit) {
        if (time < minTime) {
            minTime = time;
            return;
        }
    }
    for (int i=0;i<limit;i++) {

        if (!used[i]) {
            used[i] = 1;
            if (time+arr[n][i] > minTime) {
                used[i] = 0;
                continue;
            }
            dfs(n+1,time+arr[n][i],limit);
            used[i] = 0;
        }
    }
}
int main() {
    int n;
    cin >> n;

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }
    dfs(0,0,n);
    cout << minTime << endl;
    return 0;
}