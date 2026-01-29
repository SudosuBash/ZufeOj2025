#include <bits/stdc++.h>
using namespace std;

char c[2] = {0,0};
int main() {
    int n;
    cin >> n;
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    string s3;
    int t =0;
    for(int i=0;i<n;i++) {
        if(s1[i] != s2[i]) {
            s3 += s1[i];
        } else if(s3.size() != 0){
            t += 1;
            s3 = "";
        }
    }
    if(s3.size() != 0) {
        t+=1;
    }
    cout << t << endl;
    return 0;
}