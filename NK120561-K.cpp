#include <bits/stdc++.h>
using namespace std;

// int dfs(int i,int add,int mul,int time,int limitedtime,vector<int> arr) {
//     if(time == limitedtime) {
//         return add==mul;
//     }
//     if(time == 0 && i > 2) return 0;//这个也不可能
//     if(time == 1 && add == 1 && mul == 1 && )
//     if(add+i < mul*i) return 0; //彻底赶不上了
//     // int
//     // int l2 =  dfs(i+1,add+i,mul*i,time+1,limitedtime);

//     int l2 = dfs(i+1,add,mul,time,limitedtime,arr);
//     arr.push_back(i);
//     int l1 = dfs(i+1,add+i,mul*i,time+1,limitedtime,arr);
//     return l1 || l2;
// }
int main() {
    int T;
    cin >> T;
    for(int i=0;i<T;i++) {
        int n;
        cin >> n;
        switch(n) {
            case 1: cout << "YES" << endl << "1" << endl;break;
            case 3: cout << "YES" << endl << "1 2 3" << endl; break;
            default: cout << "NO" << endl; break;
        }
    }
}