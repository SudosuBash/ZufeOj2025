#include <bits/stdc++.h>
using namespace std;

vector<int> guibing(vector<int> arr1,vector<int> arr2) {
    int nowi = 0;
    int nowj = 0;
    vector<int> result;
    while (nowi < arr1.size() && nowj < arr2.size()) {
        if (arr1[nowi] < arr2[nowj]) {
            result.push_back(arr1[nowi]);
            nowi++;
        }
        else {
            result.push_back(arr2[nowj]);
            nowj++;
        }
    }
    while (nowi < arr1.size()) {
        result.push_back(arr1[nowi]);
        nowi++;
    }
    while (nowj < arr2.size()) {
        result.push_back(arr2[nowj]);
        nowj++;
    }
    return result;
}
vector<int> sep(vector<int> arr) {
    if (arr.size() <= 1) return arr;
    int med = (arr.size())/2;

    vector<int> left = sep(vector<int>(arr.begin(), arr.begin()+med));
    vector<int> right = sep(vector<int>(arr.begin()+med, arr.end()));

    return guibing(left, right);


}
int main() {
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        arr.push_back(data);
    }
    arr = sep(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}