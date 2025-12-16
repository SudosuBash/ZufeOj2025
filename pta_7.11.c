#include <stdio.h>
#include <string.h>
int main() {
    char c[81] = {0};
    scanf("%s",c);
    int s=0,tmp=0;
    for(int i=0;i<strlen(c);i++) {
        if(c[i] >= 48 && c[i] <= 57) {
            tmp *= 10;
            tmp += c[i] -48;
        } else {
            s += tmp;
            tmp = 0;
        }
    }
    s+=tmp;
    printf("%d\n",s);
    return 0;
}