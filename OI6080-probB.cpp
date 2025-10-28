/**
*题目描述
暑假到了，小明终于可以开心的看电视了。但是小明喜欢的节目太多了，他希望尽量多的看到完整的节目。
现在他把他喜欢的电视节目的转播时间表给你，你能帮他合理安排吗？


输入格式
输入包含多组测试数据。
每组输入的第一行是一个整数n（n<=100），表示小明喜欢的节目的总数。
接下来n行，每行输入两个整数si和ei（1<=i<=n），表示第i个节目的开始和结束时间，为了简化问题，每个时间都用一个正整数表示。
当n=0时，代表这组没有节目，输入结束。
输出格式
对于每组输入，输出能完整看到的电视节目的个数。
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * 题型 - 排序贪心
 * 思路: 选最早结束时间的
 * 本质: 选最早结束时间可以给后续更多节目留出时间，选择的机会更多。
 */

typedef struct {
    int start;
    int end;
} tmp1;

tmp1 tmp[1001];
int cmp(tmp1 t1,tmp1 t2) {
    return t1.end < t2.end;
}
int main() {
    int n;
    while (cin >> n) {
        if (n==0) return 0;
        for (int i = 0; i < n; i++) {
            cin >> tmp[i].start >> tmp[i].end;
        }
        sort(tmp,tmp+n,cmp);
        int lastTime = tmp[0].end;
        int jiemu = 1;
        for (int i=1;i<n;i++) {
            if (tmp[i].start >= lastTime) {
                jiemu++;
                lastTime = tmp[i].end;
            }
        }
        cout << jiemu << endl;
    }

    return 0;
}