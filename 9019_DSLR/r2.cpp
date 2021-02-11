#include <bits/stdc++.h>
using namespace std;


int t;
int a, b, visit[10001];

void getInput() {
    cin >> a >> b;
}

void solve() {
    queue<pair<int,string>> Q;
    Q.push({a, ""});
    visit[a] = 1;

    while(!Q.empty()) {
        int now = Q.front().first;
        string path = Q.front().second;
        Q.pop();

        int changeNum;

        if (now==b) {
            cout << path << endl;
            break;
        }
        //D
        changeNum = (now*2) % 10000;
        if (visit[changeNum]==0) {
            visit[changeNum] = 1;
            Q.push({changeNum, path+"D"});
        }

        //S
        changeNum = (now==0 ? 9999 : now-1); 
        if (visit[changeNum]==0) {
            visit[changeNum]=1;
            Q.push({changeNum, path+"S"});
        }

        //L
        changeNum = (now%1000)*10 + (now/1000);
        if (visit[changeNum]==0) {
            visit[changeNum]=1;
            Q.push({changeNum, path+"L"});
        }

        changeNum = (now/10) + (now%10)*1000;
        if (visit[changeNum]==0) {
            visit[changeNum]=1;
            Q.push({changeNum, path+"R"});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int i ,j;
    cin >> t;

    for(i=1; i<=t; i++) {
        memset(visit, 0, sizeof(visit));
        getInput();
        solve();
    }
}