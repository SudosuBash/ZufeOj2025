/*
*给定一个序列a1,a2,…,an，如果存在i < j并且ai > aj，那么我们称之为逆序对，求逆序对的数目
视频讲解

输入格式
输入：第一行为n,表示序列长度，接下来的n行，第i+1行表示序列中的第i个数。
输出格式
输出：所有逆序对总数
样例输入：
4
3 2 3 2

样例输出：
3

数据范围：N<=10^5。Ai<=10^5。时间限制为1s。
*/

#include <bits/stdc++.h>
using namespace std;

//int result = 0;
long long result = 0;
vector<int> guibing(vector<int> arr1,vector<int> arr2) {
    int size1 = arr1.size()-1;
    int size2 = arr2.size()-1;
    int size3 = size1 + size2+2;
    vector<int> arr3(size3);
    size3 -= 1;
    while (size1 >= 0 && size2 >= 0) {
        if (arr1[size1] > arr2[size2]) {
            arr3[size3] = arr1[size1];
            result += size2+1;
            size1-=1;
        } else {
            arr3[size3] = arr2[size2];
            size2-=1;
        }
        size3 -= 1;
    }
    while (size1 >= 0) {
        arr3[size3] = arr1[size1];
        size1-=1;
        size3-=1;
    }
    while (size2 >= 0) {
        arr3[size3] = arr2[size2];
        size2-=1;
        size3-=1;
    }
    return arr3;
}

vector<int> partition(vector<int> arr) {

    if (arr.size() <=1) return arr;
    int a1 = arr.size() / 2;
    vector<int> left(arr.begin(),arr.begin()+a1);
    vector<int> right(arr.begin()+a1,arr.end());
    left = partition(left);
    right = partition(right);
    return guibing(left,right);
}

int main() {
    int c;
    cin >> c;
    vector<int> arr;
    for (int i=0;i<c;i++) {
        int n;
        cin >> n;
        arr.push_back(n);
    }
    arr= partition(arr);
    cout << result << endl;
    return 0;
}