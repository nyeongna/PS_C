#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j, n;
    char s[1000];
    int a[1000];
    cin >> n;
    cin >> s;

    stack<double> Stk;
    
    for(i=1; i<=n; i++) {
        cin >> a[i];
    }

    for(i=0; i<strlen(s); i++) {
        if (s[i] >='A' && s[i] <= 'Z') {
            Stk.push(a[s[i]-'A'+1]);
        }
        else {
            double b = Stk.top();
            Stk.pop();
            double a = Stk.top();
            Stk.pop();
            if (s[i] == '+') Stk.push(a+b);
            if (s[i] == '-') Stk.push(a-b);
            if (s[i] == '*') Stk.push(a*b);
            if (s[i] == '/') Stk.push(a/b);
        }
    }
    double ans = Stk.top();
    cout.precision(2);
    cout << fixed;
    cout << ans << endl;

    
    
    return 0;
}