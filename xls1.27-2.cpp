#include <bits/stdc++.h>
using namespace std;

int used[1001] = {0};
int idx = 0;
void dfs(int index,string s2, string target) {
    if(s2.length() == target.length()) {
        if(target == s2) {
            cout << idx << endl;
        }
        idx++;
        return;
    }
    for(int i=0;i<target.length();i++) {
        if(!used[i]) {
            used[i] = 1;
            dfs(index,s2+char(i+97),target);
            used[i] = 0;
        }
    }
}
int main() {
    string s;
    cin >> s;
    dfs(0,"",s);
    return 0;
}