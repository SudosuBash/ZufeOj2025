#include <bits/stdc++.h>
using namespace std;
string zfill(string s) {
    int len = s.length();
    for (int i=0;i<4-len;i++) {
        s="0"+s;
    }
    return s;
}
string zfill2(string s) {
    int len = s.length();
    for (int i=0;i<8-len;i++) {

        s="0"+s;
    }
    return s;
}
string add(string s1,string s2) {
    string out;

    if (s1.length() < s2.length()) {
        string s3 = s1;
        s1 = s2;
        s2 = s3;
    }
    int len1 = s1.length();
    int len2 = s2.length();
    int CF = 0;
    while (len2 > 0) {
        int c1 = len1 - 8 >= 0 ? 8 : len1;
        int c2 = len2 - 8 >= 0 ? 8 : len2;
        int val1 = atoi(s1.substr(len1-c1,c1).c_str());
        int val2 = atoi(s2.substr(len2-c2,c2).c_str());
        int val3 = val1 + val2 + CF;

        if (val3 >= 1e8) {
            CF=1;
            val3 -= 1e8;
        }

        string val = to_string(val3);
        val=zfill2(val);
        out = val + out;
        len2 -= c2;
        len1 -= c1;
    }
    while (len1 > 0){
        int c1 = len1 - 8 >= 0 ? 8 : len1;
        int val1 = atoi(s1.substr(len1-c1,c1).c_str());
        int val3 = val1 + CF;

        if (val3 >= 1e8) {
            CF=1;
            val3 -= 1e8;
        }
        string val = to_string(val3);
        val=zfill2(val);
        out = val + out;
        len1 -= c1;
    }
    if (CF==1) {
        out = "1" + out;
    }
    return out;
}

int main() {
    cout << add("99999999","1");
    return 0;
}