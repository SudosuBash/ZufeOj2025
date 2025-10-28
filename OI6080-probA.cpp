/*
 * 类型1-排序贪心
*有一天，阿里巴巴赶着一头毛驴上山砍柴。砍好柴准备下山时，远处突然出现一股烟尘，弥漫着直向上空飞扬，朝他这儿卷过来，而且越来越近。靠近以后，他才看清原来是一支马队，他们共有四十人，一个个年轻力壮、行动敏捷。一个首领模样的人背负沉重的鞍袋，从丛林中一直来到那个大石头跟前，喃喃地说道：“芝麻，开门吧！”随着那个头目的喊声，大石头前突然出现一道宽阔的门路，于是强盗们鱼贯而入。阿里巴巴待在树上观察他们，直到他们走得无影无踪之后，才从树上下来。他大声喊道：“芝麻，开门吧！”他的喊声刚落，洞门立刻打开了。他小心翼翼地走了进去，一下子惊呆了，洞中堆满了财物，还有多得无法计数的金银珠宝，有的散堆在地上，有的盛在皮袋中。突然看见这么多的金银财富，阿里巴巴深信这肯定是一个强盗们数代经营、掠夺所积累起来的宝窟。为了让乡亲们开开眼界，见识一下这些宝物，他想一种宝物只拿一个，如果太重就用锤子凿开，但毛驴的运载能力是有限的，怎么才能用驴子运走最大价值的财宝分给穷人呢？阿里巴巴陷入沉思中……

假设山洞中有n种宝物，每种宝物有一定重量w和相应的价值v，毛驴运载能力有限，只能运走m重量的宝物，一种宝物只能拿一样，宝物可以分割。那么怎么才能使毛驴运走宝物的价值最大呢？




输入格式
每组测试数据的第一行是两个整数n,c (1<n,c<10000)表示该测试数据宝物数量及驴子的承载重量。
随后的n行，每行有两个正整数wi, vi分别表示第i个宝物的重量和价值(1<wi,vi<100)。
输出格式
对于每一组输入，输出毛驴运走宝物的最大价值。
每组的输出占一行,结果保留一位小数
*/
#include <bits/stdc++.h>
using namespace std;
typedef struct {
    double value; //价值
    int weight; //重量
    double destiny; //密度
}baowu;

baowu b[10001];
int cmp(baowu b1,baowu b2) {
    return b1.destiny > b2.destiny;
}
int main() {
    int n,c;
    //c:承载重量
    cin >> n >> c;
    for (int i=0;i<n;i++) {
        cin >> b[i].weight >> b[i].value;
        b[i].destiny = b[i].value / b[i].weight;
    }
    sort(b,b+n,cmp);
    double value = 0;
    int weight = 0;
    for (int i=0;i<n;i++) {
        if (weight + b[i].weight <= c) {
            weight += b[i].weight;
            value += b[i].value;
        } else {
            value += b[i].value * ((float)(c-weight) / (float)b[i].weight);
            break;
        }
    }
    printf("%.1lf",value);
   // cout << value << endl;
    return 0;
}