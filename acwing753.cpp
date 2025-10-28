#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int>& left,vector<int>& right) {
    int i=0,j=0;
    vector<int> res;
    while (i<left.size() && j<right.size()) {
        if (left[i] < right[j]) {
            res.push_back(left[i]);
            i++;
        } else {
            res.push_back(right[j]);
            j++;
        }
    }

    while (i<left.size()) {
        res.push_back(left[i]);
        i++;
    }

    while (j<right.size()) {
        res.push_back(right[j]);
        j++;
    }
    return res;
}
vector<int> guibing(vector<int>& c1) {
    if (c1.size() <= 1) return c1;
    int med = c1.size() / 2;

    vector<int>::const_iterator it1 = c1.begin();
    vector<int>::const_iterator it2 = c1.begin() + med;
    vector<int>::const_iterator it3 = c1.end();
    vector<int> left(it1,it2);
    vector<int> right(it2,it3);
    left = guibing(left);
    right = guibing(right);

    return merge(left,right);
}
int main() {
    vector<int> c1;
    c1.push_back(3);
    c1.push_back(4);
    c1.push_back(1);
    c1.push_back(2);
    c1.push_back(5);
    for (auto i : c1) {
        cout << i << " ";
    }
    cout << endl;
    c1 = guibing(c1);
    for (auto i : c1) {
        cout << i << endl;
    }
    return 0;
}