#include <bits/stdc++.h>
using namespace std;


int n;
string s;
int value[27];

void getInput() {
    cin >> n >> s;
    int i, j;
    for(i=0; i<n; i++) {
        cin >> value[i];
    }
}

void Solve() {
    stack<double> Stk;
    int i, j;
    for(i=0; i<s.size(); i++) {
        if (s[i]>= 'A' && s[i] <='Z') {
            Stk.push(value[s[i]-'A']);
        }
        else {
            double b = Stk.top();
            Stk.pop();
            double a = Stk.top();
            Stk.pop();
            if (s[i]=='+') Stk.push(a+b);
            if (s[i]=='-') Stk.push(a-b);
            if (s[i]=='*') Stk.push(a*b);
            if (s[i]=='/') Stk.push(a/b);
        }
    }
    cout << fixed << setprecision(2);
    cout << Stk.top() << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    getInput();
    Solve();
}