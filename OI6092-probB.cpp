#include <bits/stdc++.h>
#include <cctype>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    string s1,s2;
    int eq = 0;
    for(char c : s) {
        if(c == '=') {
            eq = 1;
            continue;
        } 
        if(eq) s2 += c;
        else s1 += c;
    }
    int eq1 = 0;
    for(int i=1;i<=s1.size()-1;i++) {
        int c = stoi(s1.substr(0,i));
        int c2 = stoi(s1.substr(i));
        if(c*c2 == stoi(s2)) {
            cout << s1.substr(0,i) << "*" << s1.substr(i)<<"="<<s2;
            eq1 = 1;
        }
    }
    if(!eq1) cout << "Impossible";

    return 0;
}