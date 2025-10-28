/**
*
* OJ 5996 - 问题F
* 给定一个按照升序排列的长度为 n 的整数数组，以及 q 个查询。

对于每个查询，返回一个元素k 的起始位置和终止位置（位置从 0 开始计数）。

如果数组中不存在该元素，则返回 -1 -1。
考察点: 二分
 */
#include <bits/stdc++.h>
using namespace std;

int find(vector<int> arr, int number) {
   int left=0,right=arr.size();
   int find = 0;
   while (left <= right) {
      int med = (left+right)/2;
      if (arr[med] > number) {
         right = med-1;
      } else {
         if (arr[med] == number) find = 1;
         left = med + 1;
      }
   }
   return find ? right : -1;
}

int find2(vector<int> arr, int number) {
   int left=0,right=arr.size();
   int find = 0;
   while (left <= right) {
      int med = (left+right)/2;
      if (arr[med] >= number) {
         if (arr[med] == number) find = 1;
         right = med-1;
      } else {

         left = med + 1;
      }
   }
   return find ? left : -1;
}
int main() {
   vector<int> arr;
   int n,q;
   cin >> n >> q;
   for (int i=0;i<n;i++) {
      int c;
      cin >> c;
      arr.push_back(c);
   }
   for (int i=0;i<q;i++) {
      int c;
      cin >> c;
      int r = find(arr,c);
      int r2 = find2(arr,c);
      cout << r2 << " " << r << endl;
   }
   return 0;

}