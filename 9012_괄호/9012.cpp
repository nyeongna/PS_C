#include <bits/stdc++.h>
using namespace std;

int n;

void getInput() {
    cin >> n;
}

int Check(string s) {
    int i, cnt=0;
    stack<int> Stk;
    for (i=0; i< s.size(); i++) {
        if (s[i]=='(') Stk.push(1);
        else {
            if (Stk.empty()) {
                return 0;
            }
            Stk.pop();

        }
    }
    if (Stk.empty()) return 1;
    else return 0;
    
}
void Solve() {
    int i, cnt, j;
    string s;
    for (i=1; i<=n; i++) {
        cin >> s;
        if (Check(s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
int main() {
    getInput();
    Solve();
    return 0;
}