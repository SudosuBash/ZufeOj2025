#include <iostream>
using namespace std;

int pos = 0;
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
string c0(string s) {
    int posa = -1;
    for (int i=0;i<s.size();i++) {
        if (s[i] != '0') {
            posa = i;
            break;
        }
    }
    if (posa == -1) return "0";
    return s.substr(posa,s.size()-posa);
}
string add(string s1,string s2) {
    string out;
    s1 = c0(s1);
    s2 = c0(s2);
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
        if (len1-c1==0) val = "1" + val;
        val=zfill2(val);
        out = val + out;
        len1 -= c1;
    }
    return out;
}

string shr(string s) {
    for (int i=0;i<pos;i++) {
        s += "0000";
    }
    pos += 1;
    return s;
}

string part(string s1,string s2,int pos1,int add1) {
    int len2 = s2.length();
    int value1 = atoi(s1.substr(pos1,add1).c_str());
    int OFValue = 0;
    string ret = "";
    while (len2 > 0 || OFValue != 0) {
        int c2 = len2 - 4 >= 0 ? 4 : len2;
        if (len2 == 0) c2 = 1;
        int value2;
        if (len2 != 0) value2 = atoi(s2.substr(len2-c2,c2).c_str());
        else value2 = 0;
        int res = value1 * value2 + OFValue;
        int low8 = res % 10000;
        int high8 = res / 10000;
        OFValue = high8;
        string vala = to_string(low8);
        vala = zfill(vala);
        ret=  vala+ ret;
        len2 -= c2;
    }
    return ret;
}
int main() {
    string s1,s2;
    cin >> s1 >> s2;
    int len1 = s1.length();
    int len2 = s2.length();
    if (len1<len2) {
        string s3=s1;
        s1=s2;
        s2=s3;
    }
    len1 = s1.length();
    len2 = s2.length();
    string res = "0";
    while (len1 > 0) {
        int c1 = len1 - 4 >= 0 ? 4 : len1;
        res = add(res,shr(part(s1,s2,len1-c1,c1)));
        len1 -= c1;
    }
    cout << c0(res) << endl;
    return 0;
}