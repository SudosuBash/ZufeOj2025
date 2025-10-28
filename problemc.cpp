#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef struct {
    int id;
    int score;
    int nengli;
}stu;
vector<stu> stu1;
vector<stu> shengli,shibai;
int N,R,Q;

bool cmp(stu a,stu b) {
    if (a.score == b.score) return a.id < b.id;
    return a.score > b.score;
}
void bisai() {

    for (int i=0;i<N*2;i+=2 ) {
        if (stu1[i].nengli > stu1[i+1].nengli) {
            stu1[i].score ++;
            shengli.push_back(stu1[i]);
            shibai.push_back(stu1[i+1]);
        } else {
            stu1[i+1].score ++;
            shengli.push_back(stu1[i+1]);
            shibai.push_back(stu1[i]);
        }
    }
}
vector<stu> hebing() {
    vector<stu> result;
    int i = 0,j = 0;
    while (i < shengli.size() && j < shibai.size()) {
        if (shengli[i].score > shibai[j].score || (shengli[i].score == shibai[j].score &&
            shengli[i].id < shibai[j].id)) {
            result.push_back(shengli[i]);
            i++;
        } else {
            result.push_back(shibai[j]);
            j++;
        }
    }
    while (i<shengli.size()) {
        result.push_back(shengli[i]);
        i++;
    }
    while (j<shibai.size()) {
        result.push_back(shibai[j]);
        j++;
    }
    return result;
}
// vector<stu> guipai(vector<stu> a,vector<stu> b) {
//     int left=0,right = 0;
//     vector<stu> res;
//     while (left < a.size() && right < b.size()) {
//         if (a[left].score > b[right].score || (a[left].score == b[right].score && a[left].id < b[right].id )) {
//             res.push_back(a[left]);
//             left++;
//         } else {
//             res.push_back(b[right]);
//             right++;
//         }
//     }
//     while (left < a.size()) {
//         res.push_back(a[left]);
//         left++;
//     }
//     while (right < b.size()) {
//         res.push_back(b[right]);
//         right++;
//     }
//     return res;
// }
//
// vector<stu> partition(vector<stu> a) {
//
//     if (a.size() <= 1) return a;
//     int left = 0,right = a.size();
//     int med = (left + right) / 2;
//     vector<stu> leftv = partition(vector<stu>(a.begin(),a.begin()+med));
//     vector<stu> rightv = partition(vector<stu>(a.begin()+med,a.end()));
//     return guipai(leftv,rightv);
// }

int main() {
    cin >> N >> R >> Q;
    for (int i=0;i<N*2;i++) {

        stu stu;
        stu.id = i+1;
        cin >> stu.score;
        stu1.push_back(stu);
    }

    for (int i=0;i<N*2;i++) cin >> stu1[i].nengli;
    sort(stu1.begin(),stu1.end(),cmp); //官方排序，pass
    //stu1 = partition(stu1) //时间复杂度O(n logn) AC92% 超时
    vector<stu>* res = &stu1; //便于打断点
    for (int i=0;i<R;i++) {
        bisai();
        stu1 = hebing();
        shengli = vector<stu>(); //重置
        shibai = vector<stu>(); //重置
    }

    cout << stu1[Q-1].id;
    return 0;
}