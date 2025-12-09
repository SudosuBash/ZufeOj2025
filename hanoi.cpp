#include <iostream>
using namespace std;

void hanoi(int n,char a,char b,char c) {
    if(n==1) {
        cout << a << "->" << c << endl; 
        return;
    }
    hanoi(n-1,a,c,b);
    cout << a << "->" << c << endl;
    hanoi(n-1,b,a,c);
}
int main() {
    int n;
    cin >> n;
    hanoi(n,'1','2','3');
    return 0;
}