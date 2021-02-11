#include <bits/stdc++.h>
using namespace std;

string s, p;
char res[1000001];

void getInput() {
    cin >> s >> p;
}

void Solve() {
    int idx=0, i,j, flag=1;
    
    for(i=0; i< s.size(); i++) {
        res[idx++] = s[i];
        // 마지막 폭탄 문자와 같다면
        if (s[i] == p[p.size()-1]) {
            flag=1;
            // 비교를 시작한다.
            for(j=0; j < p.size(); j++) {
                if (res[idx-p.size()+j] != p[j]) {
                    flag=0;
                    break;
                }
            }
            if (flag) {
                idx = idx - p.size();
            }
        }
    }
    
    if (idx==0) cout << "FRULA";
    else {
        // idx까지만 출력한다. 그 이후로는 지워진 문자열이기 때문.
        for(i=0; i< idx; i++) {
            cout << res[i];
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    getInput();
    Solve();
}