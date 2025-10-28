#include <iostream>
#include <vector>
using namespace std;

typedef struct node {
    int index;
    vector<node*> next;
    int valid = 1;
}node,*pnode;

vector<vector<int>> vpath;
int n;
int prime(int n) {
    if (n==1 || n==0) return 0;
    for (int i=2;i<n;i++) {
        if (n%i==0) return 0;
    }
    return 1;
}

void dfs(node* root,node* tnode,vector<int> arr,int time,vector<int> path) {
    int ni = tnode->index + 1;
    arr[tnode->index] = 1;
    int hit = 0;
    for (int i=0;i<arr.size();i++) {
        if (arr[i] == 1) continue;
        if (prime(ni + (i+1))) {
            pnode p = new node;
            p->index = i;
            path.push_back(tnode->next.size());
            tnode->next.push_back(p);
            dfs(root,p,arr,time+1,path);
            hit = 1;
            path.pop_back();
        }
    }
    if (!hit) {
        if (prime(ni + 1)) time ++;
        if (time == n) {
            vpath.push_back(path);
        }
    }
}

int main() {
    cin >> n;
    vector<int> arr;
    for (int i=0;i<n;i++) {
        arr.push_back(0);
    }
    pnode p = new node;
    p->index = 0;
    vector<int> c;
    dfs(p,p,arr,0,c);
    vector<vector<int>> npath = vpath;
    cout << npath.size() << endl;
    return 0;
}