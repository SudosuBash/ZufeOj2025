#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<int> st;
    int res = 0;
    for(int i=0;i<s.size();i++) {
        if(s[i] == 'p') {
            st.push(1);
        } else {
            if(!st.empty()) st.pop();
            else res += 1;
        }
    }
    cout << res;
    return 0;
}