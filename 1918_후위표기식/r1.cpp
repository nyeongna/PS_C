#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int i, j;
    stack<char> Stk;
    string s,ans;
    cin >> s;
    for(i=0; i<s.size(); i++) {
        // char
        if (s[i] >= 'A' && s[i] <= 'Z') {
            ans.push_back(s[i]);
        }
        // (
        else if (s[i] == '(') {
            Stk.push('(');
        }
        // )
        else if (s[i] == ')') {
            while (Stk.top() != '(') {
                ans.push_back(Stk.top());
                Stk.pop();
            }
            Stk.pop();
        }
        //operand
        else {
            // + -
            if(s[i] == '+' || s[i] == '-') {
                while (!Stk.empty() && Stk.top() != '(') {
                    ans.push_back(Stk.top());
                    Stk.pop();
                }
                Stk.push(s[i]);
            }
            // * /
            else {
                while (!Stk.empty() && Stk.top() != '(' && Stk.top() != '+' && Stk.top() != '-') {
                    ans.push_back(Stk.top());
                    Stk.pop();
                }
                Stk.push(s[i]);
            }
        }
    }
    while (!Stk.empty()) {
        ans.push_back(Stk.top());
        Stk.pop();
    }
    cout << ans << endl;
    return 0;
}