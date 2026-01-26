// #include <bits/stdc++.h>
// using namespace std;

// #define bc 3
// #define cx first
// #define cy second

// int map125[bc][bc] = {0};
// int times = 0;
// typedef pair<int,int> pii;
  
// typedef struct {
//     int x;
//     int y;
//     vector<pii> piis;
// } solv_t;


// void bfs() {
//     queue<solv_t> qs;
//     solv_t s;
//     s.x = 0;
//     s.y = 0;
//     s.piis = vector<pii>();

//     pii p;
//     p.cx = s.x;
//     p.cy = s.y;
//     s.piis.push_back(p);
//     qs.push(s);

//     while(!qs.empty()) {
//         solv_t s2 = qs.front();
//         if(s2.x + s2.y == bc) {
//             times ++;
//         }
//         if(s2.x < 0 || s2.y < 0)
//             continue; //无效
//         if(s2.x + s2.y > bc) continue; //无效
//         if(find(s.piis.begin(),s.piis.end()) ==

//     }
// }
// int main() {

    
//     dfs(bc-1,0);
//     // cout << res << endl;
//     cout << times << endl;
//     return 0;
// }