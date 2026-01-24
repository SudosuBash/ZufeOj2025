#include <bits/stdc++.h>
using namespace std;

typedef struct step_t {
    int step;
    int zx;
    int zy;
    vector<vector<int>> arr;
} step_t;


vector<vector<int>> arr;
map<string,int> a;
string to_arr_str(vector<vector<int>> v) {
    string s2 = "";
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            s2+=to_string(v[i][j]);
        }
    }
    return s2;
}
void solv(int zx,int zy, vector<vector<int>> vec) {
    step_t st = {
        .step = 0,
        .zx = zx,
        .zy = zy,
        .arr = vec
    };
    queue<step_t> qo;
    qo.push(st);
    while (!qo.empty()) {
        step_t st2 = qo.front();
        string str = to_arr_str(st2.arr);
        if(a[str] == 1) {
            qo.pop();
            continue;
        }
        a[str] = 1;
        if(str == "123456780") {
            cout << st2.step << endl;
            return;
        }
        if(st2.zx != 0) {
            swap(st2.arr[st2.zy][st2.zx-1],st2.arr[st2.zy][st2.zx]);
            st2.zx = st2.zx-1;
            st2.step += 1;
            qo.push(st2);
        }

        st2 = qo.front();
        if(st2.zx != 2) {
            swap(st2.arr[st2.zy][st2.zx+1],st2.arr[st2.zy][st2.zx]);
            st2.zx = st2.zx+1;
            st2.step += 1;
            qo.push(st2);
        }

        st2=qo.front();
        if(st2.zy != 0) {
            swap(st2.arr[st2.zy-1][st2.zx],st2.arr[st2.zy][st2.zx]);
            st2.zy = st2.zy-1;
            st2.step += 1;
            qo.push(st2);
        }

        st2 = qo.front();
        if(st2.zy != 2) {
            swap(st2.arr[st2.zy+1][st2.zx],st2.arr[st2.zy][st2.zx]);
            st2.zy += 1;
            st2.step += 1;
            qo.push(st2);
        }
        qo.pop();

    }
    
}
int main() {
    
    string s = "";
    cin >> s;
    int zx,zy;
    for(int i=0;i<3;i++) {
        vector<int> v = vector<int>();
        for(int j=0;j<3;j++) {
            v.push_back(s[i*3+j] - 48);
            if(s[i*3+j] - 48 == 0){
                zx = j;
                zy = i;
            }
        }
        arr.push_back(v);
    }
    solv(zx,zy,arr);
    return 0;
}