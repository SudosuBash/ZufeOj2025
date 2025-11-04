#include <bits/stdc++.h>
#include <cctype>
#include <string>

using namespace std;

int main() {
    int c1;
    cin >> c1;
    cin.ignore();
    string s;
    getline(cin,s);
    s+=" ";
    int n = 0;
    int nmax = 0;
    for(char c: s) {
        if(c==' ') {
           nmax = max(n,nmax); 
           n = 0;
        } else if(isupper(c)) {
            n += 1;
        }
    }
    cout << nmax;
    return 0;
}