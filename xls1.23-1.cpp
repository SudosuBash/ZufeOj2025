#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string target = "";

    for(int i=0;i<s.size()-1;i++) {
        if(s[i+1] >= 48 && s[i+1] <= 57) {
            int a = s[i+1] - 48;
            for(int j=0;j<a;j++) {
                target = target + s[i];
            }
        } else if(!(s[i] >= 48 && s[i] <= 57)) {

            target = target + s[i];
            if(i==s.size() -2) {
                target+=s[i+1];
            }
        }
    }
    cout << target << endl;
    return 0;
}