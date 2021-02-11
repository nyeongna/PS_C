#include <bits/stdc++.h>
using namespace std;


int n;
int ans;
deque<pair<int,int> > ch;

int Check(int row, int col) {
    for(int i=0; i<ch.size(); i++) {
        int r = ch[i].first;
        int c = ch[i].second;
        if (r == row) return 1;
        if (c == col) return 1;
        if (abs(row-r) == abs(col-c)) return 1;
    }
    return 0;
}
void DFS(int row, int cnt) {
    if (row==n && cnt == n) {
        ans++;
        return;
    }
    for(int col=0; col<n; col++) {
        int flag = Check(row, col);
        if (flag==0) {
            ch.push_back({row,col});
            DFS(row+1, cnt+1);
            ch.pop_back();
        }
    }
}
int main() {
    cin >> n;
    DFS(0, 0);
    cout << ans << endl;
    return 0;
}