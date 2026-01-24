#include <bits/stdc++.h>
using namespace std;

typedef struct step_t {
    int step;
    int zx;
    int zy;
    int from;
    vector<vector<int>> arr;
    string operate;
    step_t* prev;
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
    step_t* st = (step_t*)calloc(1,sizeof(step_t));
    st->step = 0;
    st->zx = zx;
    st->zy = zy;
    st->arr = vec;

    queue<step_t*> qo;
    qo.push(st);

    while (!qo.empty()) {
        step_t* st2 = qo.front();
        string str = to_arr_str(st2->arr);
        if(a[str] == 1) {
            qo.pop();
            continue;
        }
        a[str] = 1;
        
        if(str == "123456780") {
            step_t* start = st2;
            cout << "Result: ";
            string s = "";
            while(start->prev != NULL) {
                s = to_string(start->from) + s;
                start = start->prev;
            }
            cout << s << endl;
            cout << "Step: " << s.length() << endl;
            return;
        }

        if(st2->zx != 0) {
            step_t* st3 = (step_t*)calloc(1,sizeof(step_t));
            *st3 = *st2;
            st3->prev = st2;
            st3->from = st3->arr[st3->zy][st3->zx-1];
            swap(st3->arr[st3->zy][st3->zx-1],st3->arr[st3->zy][st3->zx]);
            
            st3->zx = st3->zx-1;
            st3->step += 1;
            
            qo.push(st3);
        }

        if(st2->zx != 2) {
            step_t* st3 = (step_t*)calloc(1,sizeof(step_t));
            *st3 = *st2;
            st3->prev = st2;
            st3->from = st3->arr[st3->zy][st3->zx+1];
            swap(st3->arr[st3->zy][st3->zx+1],st3->arr[st3->zy][st3->zx]);
            st3->zx = st3->zx+1;
            st3->step += 1;
            qo.push(st3);
        }

        if(st2->zy != 0) {
            step_t* st3 = (step_t*)calloc(1,sizeof(step_t));
            *st3 = *st2;
            st3->prev = st2;
            st3->from = st3->arr[st3->zy-1][st3->zx];
            swap(st3->arr[st3->zy-1][st3->zx],st3->arr[st3->zy][st3->zx]);
            st3->zy = st3->zy-1;
            st3->step += 1;
            qo.push(st3);
        }

        if(st2->zy != 2) {
            step_t* st3 = (step_t*)calloc(1,sizeof(step_t));
            *st3 = *st2;
            st3->prev = st2;
            st3->from = st3->arr[st3->zy+1][st3->zx];
            swap(st3->arr[st3->zy+1][st3->zx],st3->arr[st3->zy][st3->zx]);
            st3->zy += 1;
            st3->step += 1;
            qo.push(st3);
        }
        qo.pop();

    }
    cout << "No result..." << endl;
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