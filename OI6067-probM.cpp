/**
*题目描述
翰翰和达达饲养了 N 只小猫，这天，小猫们要去爬山。

经历了千辛万苦，小猫们终于爬上了山顶，但是疲倦的它们再也不想徒步走下山了（呜咕>_<）。

翰翰和达达只好花钱让它们坐索道下山。

索道上的缆车最大承重量为 W，而 N 只小猫的重量分别是 C1、C2……CN。

当然，每辆缆车上的小猫的重量之和不能超过 W。

每租用一辆缆车，翰翰和达达就要付 1 美元，所以他们想知道，最少需要付多少美元才能把这 N 只小猫都运送下山？

https://www.bilibili.com/video/BV1RPe4zPEBy/?vd_source=398d1f1b78a749026d665c575cad4731


输入格式
第 1 行：包含两个用空格隔开的整数，N 和 W。
第 2..N+1 行：每行一个整数，其中第 i+1 行的整数表示第 i 只小猫的重量 Ci。

输出格式
输出一个整数，表示最少需要多少美元，也就是最少需要多少辆缆车。
数据范围
1≤N≤18,
1≤Ci≤W≤108

*/
#include <bits/stdc++.h>
using namespace std;
int n,w;
//n只小猫
//w承载的最大重量

int cmp(int a,int b) { return a > b;}
int weights[21] = {0};
int lanche[21] = {0};
int used[21] = {0};
int minCount = 2147483647;
// void dfs(int weight,int count,int lancheIndex) {
//     if (count == n) {
//         if (lancheIndex < minCount) minCount = lancheIndex;
//         return;
//     }
//     lanche[lancheIndex] = weight;
//
//     for (int i=0;i<n;i++) {
//         if (!used[i]) {
//             used[i] = 1;
//             if (weight+weights[i] < w) {
//                 dfs(weight+weights[i],count+1,lancheIndex); //选择
//             }
//             if (lancheIndex + 1 < minCount) {
//                 dfs(weights[i],count+1,lancheIndex+1); //不选
//             }
//             used[i] = 0;
//         }
//     }
// }

void dfs(int dangqianLanche,int currentCat) {
    if (dangqianLanche > minCount) return;
    if (currentCat == n) {
        if (dangqianLanche < minCount) {
            minCount = dangqianLanche;

        }
        return;
    }
    for (int i=0;i<dangqianLanche;i++) {
        if (lanche[i] + weights[currentCat] <= w) {
            lanche[i] += weights[currentCat];
            dfs(dangqianLanche,currentCat+1);
            lanche[i] -= weights[currentCat];
        }
    }
    lanche[dangqianLanche] = weights[currentCat];
    dfs(dangqianLanche+1,currentCat+1);
    lanche[dangqianLanche] = 0;
}
int main() {
    cin >> n >> w;
    for (int i=0;i<n;i++) {
        cin >> weights[i];
    }
    sort(weights,weights+n,cmp);
    dfs(1,0);
    cout << minCount << endl;
    return 0;
}