#include <bits/stdc++.h>

using namespace std;

int scorec = 0;
vector<int> shetuanScores;
vector<int> shetuanMeters;
void dfs(int index,int allShetuan,int score,vector<int> meters) {
    if (allShetuan == meters.size()) {
        int cmax = *max_element(meters.begin(),meters.end());
        int allScore = cmax * 2 + score;
        if (allScore > scorec) scorec = allScore;
        return;
    }
    if (index >= shetuanScores.size()) return;
    dfs(index+1,allShetuan,score,meters);

    meters.push_back(shetuanMeters[index]);
    dfs(index+1,allShetuan,score+shetuanScores[index],meters);

}
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        int c;
        cin >> c;
        shetuanMeters.push_back(c);
    }
    for (int i=0;i<n;i++) {
        int c;
        cin >> c;
        shetuanScores.push_back(c);
    }
    for (int i=0;i<n;i++) {
        scorec=0;
        dfs(0,i+1,0,vector<int>());
        cout << scorec << endl;
    }

    return 0;
}