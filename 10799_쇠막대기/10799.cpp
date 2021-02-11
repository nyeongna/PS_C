#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int i, j;
    stack<int> Stk;
    int cnt=0;
    for (i=0; i<s.size(); i++) {
        if (s[i]=='(') Stk.push(1);
        else
            if (s[i-1]== '(') {
                Stk.pop();
                cnt += Stk.size();
            }
            else {
                Stk.pop();
                cnt += 1;
            }

    }
    cout << cnt;
    return 0;
}


