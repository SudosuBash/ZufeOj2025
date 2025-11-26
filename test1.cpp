#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int left;
    int right;
    int need;
} tmp1;

int cmp(tmp1 a1,tmp1 a2) {
    return a1.right < a2.right;
}
int main() {
    vector<tmp1> v;
    int n,h;
    cin >> n >> h;
    for(int i=0;i<h;i++) {
        int l,r,t1;
        cin >> l >> r >> t1;
        tmp1 tmp = {0};
        tmp.left = l;
        tmp.right = r;
        tmp.need = t1;
        v.push_back(tmp);
    }
    int qujian[30001] = {0};
    int res = 0;
    sort(v.begin(),v.end(),cmp);
    //排序: 按照区间末位置从小到大排序 *: Q1
    for(tmp1 t:v) {
        //第一步:统计
        int tmp2 = 0;//统计区间数量
        for(int i=t.left;i<=t.right;i++) {
            if(qujian[i]) tmp2++;
        }
        //第二步:种树
        if(tmp2 < t.need) {
            int i = t.need-tmp2; //获取剩余的树的数量
            for(int j=t.right;j>=t.left && i>0;j--) { //从后往前种
                //为什么要从后往前种?
                //从后往前种，
                if (qujian[j]) {
                    continue;
                }
                qujian[j] = 1;
                res += 1;
                i--;
            }
            if (i>0) { //超出承受范围，直接判定不可能
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cout << res << endl;
    return 0;
}

/**
 * 本质:
* 1.为什么排序是t.right?
* A1.因为区间末位置从小到大能保证访问到每一个重合区间，进而能保证优先在重合区间内种树。
* 2.不能排序t.left吗?
* A2.可以，但若排序t.left的话，需要按照t.left从大往小排序，才能保证第一个访问到的区间是重合的区间，保证第一步不会种错树，进而保证后面都不会种错。
* 3.为什么从右到左种?
* A3.本题的思路是尽量把树种到重合区间。从右到左种的核心正是为了覆盖重合区间，让重合区间先种树。
* 而最后一个访问到的若不是重合区间，代表已经没有重合区间了(在不间断的区间内)，所以在不重合的区间种满树就好。
* 若第一个就访问非重合区间，会导致第一次就种错，导致后面全部种错。这也是A2要保证t.left从大到小访问的原因。
*/