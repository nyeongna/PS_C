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
        // ������ ��ź ���ڿ� ���ٸ�
        if (s[i] == p[p.size()-1]) {
            flag=1;
            // �񱳸� �����Ѵ�.
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
        // idx������ ����Ѵ�. �� ���ķδ� ������ ���ڿ��̱� ����.
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