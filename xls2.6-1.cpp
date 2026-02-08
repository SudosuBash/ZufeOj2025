#include <bits/stdc++.h>
using namespace std;

/**
 * 种树问题
 */

int jinhao[1000001] = {0};
int main() {
    vector<int> pos;
    string s1,s2;
    cin >> s1 >> s2;
    for(int s=0;s<=s1.size()-s2.size();s++) {
        if(s1.substr(s,s2.size()) == s2) {
            pos.push_back(s);
        }
    }
    int cnt = 0;
    for(int i:pos) {
        int selected = 0;
        
        int posc = i;
        int final = posc + s2.size() - 1;
        for(int j=posc;j<=final;j++) {
            if(jinhao[j]) {
                selected = 1;
                break;
            }
        }
        if(selected) continue;
        jinhao[final] = 1;
        cnt+=1;
    }
    cout << cnt << endl;
    return 0;
}