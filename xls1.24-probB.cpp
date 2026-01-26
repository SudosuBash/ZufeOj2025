#include <bits/stdc++.h>

using namespace std;

int bucket[601] = {0};

int main() {
    int n,w;
    scanf("%d%d",&n,&w);
    vector<int> v;
    for(int i=1;i<=n;i++) {
        
        int fs;
        scanf("%d",&fs);

        if(bucket[fs] == 0) {
            v.push_back(fs);
            sort(v.begin(),v.end(),greater<int>());
        }
        bucket[fs] += 1;

        int renshu =(int)floor((i * w) / 100);
        

            int c = 0;
            for(int j=0;j<v.size();j++) {  //
                c+=bucket[v[j]];
                if(c >= renshu) {
                    printf("%d ",v[j]);
                    // cout << v[j] << " ";
                    break;
                }
            }

    }
}