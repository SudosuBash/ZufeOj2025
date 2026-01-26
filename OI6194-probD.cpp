#include <bits/stdc++.h>
using namespace std;
char a[3] = {'B','I','F'};
char tree[10001] = {0};
void order(int index,int limit) {
    if(index >= limit) return;
    order(index*2+1,limit);
    order(index*2+2,limit);
    cout << tree[index];
}
void dfs(int start_index) {

    for(int index=start_index-1;index < (start_index)*2-1;index+=2) {
        int target_index = (index) / 2;
        if(tree[index] == 'I' && tree[index+1] == 'I') {
            tree[target_index] = 'I';
        }
        if(tree[index] == 'B' && tree[index+1] == 'B') {
            tree[target_index] = 'B';
        }
        if((tree[index] == 'B' && tree[index+1] == 'I') || 
            (tree[index] == 'I' && tree[index+1] == 'B')) {
                tree[target_index] = 'F';
            }
        if(tree[index] == 'F' || tree[index+1] == 'F') {
            tree[target_index] = 'F';
        }
    }
    if(start_index == 1) {
        return;    
    }
    dfs((start_index)/2);
}
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++) {
        tree[s.length()+i-1] = a[s[i]-48];
    }
    dfs(s.length());
    order(0,s.length()*2-1);
    return 0;
}