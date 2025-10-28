#include <bits/stdc++.h>

using namespace std;

int reverse(int a) {
    int c = a;
    int maxNumber=0,minNumber=10;
    int another = 0;
    for (int i=0;i<3;i++) {
        int num = a%10;
        if (num > maxNumber) maxNumber = num;
        if (num < minNumber) minNumber = num;

        a/=10;
    }

    for (int i=0;i<3;i++) {
        int num = c%10;
        if (num != maxNumber && num != minNumber) {
            another = num;
        }
        c /= 10;
    }
    int cmax = minNumber + another * 10 + maxNumber * 100;
    int cmin = maxNumber + another * 10 + minNumber * 100;
    return cmax - cmin;
}
int main() {
    int a;
    cin >> a;
    int c = 0;
    while (a != 495) {
        a=reverse(a);
        c+=1;
    }
    cout << c << endl;
    return 0;
}