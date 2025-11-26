#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[12][7] = {0};
    for (int i=0;i<n;i++) {
        int w; //WEEK W
        string d; //DAY D
        cin >> w >> d;
        int day = 0;
        if (d == "Mon") {
            day = 0;
        } else if (d == "Tue") {
            day = 1;
        } else if (d == "Wed") {
            day = 2;
        } else if (d == "Thu") {
            day = 3;
        } else if (d == "Fri") {
            day = 4;
        } else if (d == "Sat") {
            day = 5;
        } else if (d == "Sun") {
            day = 6;
        }
        a[w-1][day] = 1;
    }
    int sumd = 0;
    for (int i=0;i<12;i++) {
        int fin = 0;
        for (int j=0;j<7;j++) {
            fin += a[i][j];
        }
        sumd += (fin >= 5);
    }
    if (sumd >= 8) {
        cout << "Ayaka Yes!" << endl;
    } else {
        cout << "Ayaka No!" << endl;
    }
    return 0;
}
