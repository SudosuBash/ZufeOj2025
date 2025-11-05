/**
*题干翻译
教育改革后，波尔卡普（Polycarp）在学校只学两门课：安全课（Safety Studies）和体育课（PE，即 Physical Education）。在漫长的第四学期里，他在这两门课上一共得了 n 个分数。老师在成绩册上记录分数时，并没有注明对应的科目，只写了分数本身。
现在他要把成绩册拿给严厉的父母看。波尔卡普知道，最近的家长会上，老师已经告知家长他的安全课有 a 个分数，体育课有 b 个分数（a+b=n）。
现在波尔卡普要给每个分数前标注对应的科目，满足以下条件：
安全课的分数恰好有 a 个；
体育课的分数恰好有 b 个；
两门课的平均分之和最大。
某门课的平均分等于该课所有分数的总和除以分数的个数。除法按实数计算，不进行四舍五入。波尔卡普的目标是最大化 x1+x2，其中 x1 是第一门课（安全课）的平均分，x2 是第二门课（体育课）的平均分。
输入
第一行包含一个整数 n（2≤n≤10^5），表示波尔卡普成绩册上的分数总数。
第二行包含两个正整数 a、b（1≤a,b≤n-1，且 a+b=n）。
第三行包含 n 个整数 t1、t2、…、tn（1≤ti≤5），代表波尔卡普的各个分数。
输出
输出一个整数序列 f1、f2、…、fn，其中 fi（1≤fi≤2）表示第 i 个分数对应的科目编号（1 代表安全课，2 代表体育课）。
如果存在多个可行方案，输出字典序最小的序列。
字典序定义：对于两个序列 p1,p2,…,pn 和 q1,q2,…,qn，若存在某个 j（1≤j≤n），使得对于所有 1≤i<j 都有 pi=qi，且 pj<qj，则称 p 序列字典序小于 q 序列。
示例
输入53 24 4 5 4 4
输出1 1 2 1 2
输入42 23 5 4 5
输出1 1 2 2*/

#include <algorithm>
#include <iostream>
using namespace std;

typedef struct {
    int type;
    int score;
    int index;
} SCORE;
int cmp1(SCORE a1,SCORE a2) {
    return (a1.score > a2.score) || (a1.score == a2.score && a1.index < a2.index);
}
int main() {
    int types[10001] = {0};
    int n;
    cin >> n;
    int a,b;
    cin >> a >> b;
    SCORE arrA[10001] = {0},arrB[10001] = {0};
    for (int i=0;i<n;i++) {
        int t;
        cin >> t;
        arrA[i].score = b * t;
        arrB[i].score = a * t;
        arrA[i].index = i+1;
        arrA[i].type = 1;
        arrB[i].type = 2;
        arrB[i].index = i+1; //避免0的影响
    }

    sort(arrA,arrA+n,cmp1);
    sort(arrB,arrB+n,cmp1);

    SCORE combined[20001];
    int i=0,j=0,index=0;
    while (i<n && j<n) {
        // int jud = 0;
        // if (arrA[i].score > arrB[j].score) jud = 1;
        // if (arrA[i].score == arrB[j].score) {
        //     if (arrA[i].type == 1 && arrB[j].type == 2) jud = 1;
        //     if (arrA[i].type == 1 && arrB[j].type == 1) jud = arrA[i].index < arrB[j].index;
        //     if (arrA[i].type == 2 && arrB[j].type == 2) jud = arrA[i].index > arrB[j].index;
        // }
        if (arrA[i].score > arrB[j].score ||
                (arrA[i].score == arrB[i].score && arrA[i].index < arrB[j].index)) {
            combined[index] = arrA[i];
            i+=1;
        }
        else {
            combined[index] = arrB[j];
            j+=1;
        }
        index++;
    }
    while (i<n) {
        combined[index] = arrA[i];
        i+=1;
        index++;
    }
    while (j<n) {
        combined[index] = arrB[j];
        j+=1;
        index++;
    }
    //合并得到最终数组
    int c1 = 0,c2 = 0;
    for (int i1=0;i1<n*2;i1++) {
        if (types[combined[i1].index] == 0) {
            if (c1 < a) {
                types[combined[i1].index] = 1;
                c1 += 1;
            }
            else if (c2 < b) {
                types[combined[i1].index] = 2;
                c2 += 1;
            }
        }
    }

}