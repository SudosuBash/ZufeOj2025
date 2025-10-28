#include <bits/stdc++.h>
using namespace std;

int getIndex(int s,int t) {
    return s+rand()%(t-s);
}
void quicksort(vector<int>& arr,int left,int right) {
    if (right <= left) return;
    int index = getIndex(left,right);
    int n=left,m=right;
    while (n <= m) {
        while (arr[n] <= arr[index] && n <= m) {
            n++;
        }
        while (arr[m] >= arr[index] && n <= m) {
            m--;
        }
        if (n<m) {
            swap(arr[n],arr[m]);
        }
    }
    if (n<index) {
        swap(arr[index],arr[n]);
        quicksort(arr,left,n-1);
        quicksort(arr,n+1,right);
    } else {
        swap(arr[index],arr[m]);
        quicksort(arr,left,m-1);
        quicksort(arr,m+1,right);
    }

}
int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        vector<int> arr;
        int size;
        cin >> size;
        int value;
        for (int j=0;j<size;j++) {
            cin >> value;
            arr.push_back(value);
        }

        quicksort(arr,0,arr.size()-1);
        for (int i=0;i<arr.size();i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}