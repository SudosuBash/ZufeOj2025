#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 20+2;
const int MAXUSED = 2;
string word[MAXN];//单词
int used[MAXN];//单词已经使用次数
int relation[MAXN][MAXN];
int sum;//当前龙单词长度
int ans;//最长的长度
int n;//
string dragon;

//用第 i 个单词开始接龙
void dfs(int i) {
    //标志位，如果发生遍历说明数据构造没有结束
    bool flag = true;
    //遍历
    for (int j=0; j<n; j++) {
        //第 j 个单词没有超过使用限制
        //并且第 j 个单词可以接着第 i 个单词后面
        if (used[j]<MAXUSED && relation[i][j]>0) {
            used[j]++;
            sum += (word[j].length()-relation[i][j]);
            dragon += word[j].substr(relation[i][j], word[j].length()-relation[i][j]);
            dfs(j);
            sum -= (word[j].length()-relation[i][j]);
            used[j]--;
            dragon = dragon.substr(0, dragon.length()-(word[j].length()-relation[i][j]));
            flag = false;
        }
    }

    if (true == flag) {
        //cout << dragon << " " << sum << endl;
        ans = max(ans, sum);
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin>>word[i];
    }
    char ch;
    cin >> ch;

    //找龙头和构建重复字符表
    vector<int> head;
    for (int i=0; i<n; i++) {
        if (ch==word[i].at(0)) {
            head.push_back(i);
        }
        //第i个单词后面接上第j个单词，将重复 k 个字符
        for (int j=0; j<n; j++) {
            int tt = min(word[i].length(), word[j].length());
            string tmp1, tmp2;
            for (int k=1; k<=tt; k++) {
                //word[i]逆序获取
                tmp1 = word[i].substr(word[i].length()-k, k);
                //word[j]正序获取
                tmp2 = word[j].substr(0, k);
                if (tmp1==tmp2) {
                    relation[i][j]=k;
                    break;
                }
            }

            //包含关系
            if (relation[i][j]==tt) {
                relation[i][j]=0;
            }
        }
    }

    int index;
    vector<int>::iterator it;
    for (it=head.begin(); it<head.end(); it++) {
        index = *it;
        used[index]++;
        sum += word[index].length();
        dragon = word[index];
        dfs(index);
        sum -= word[index].length();
        used[index]--;
    }

    cout << ans << endl;

    return 0;
}