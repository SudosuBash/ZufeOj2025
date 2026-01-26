#include <bits/stdc++.h>
using namespace std;

int bucket[100001] = {0};
vector<int> nums;
int yz = 0;
//wc,这样真行啊,我以为要超时了
int gcd(int a,int b) {
    if(a%b==0) return b;
    int g = a % b;
    a = b;
    b = g;
    return gcd(a,b);
}
int main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        int d;
        scanf("%d",&d);
        nums.push_back(d);
    }

    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-1;i++) {
        if(i == 0) {
            yz = nums[i+1] - nums[i];
        } else {
            yz = gcd(yz,nums[i+1]-nums[i]);
            if(yz == 1) break;
        }
    }
    cout << ((nums[nums.size()-1] - nums[0]) / yz) + 1 << endl;
    return 0;
}