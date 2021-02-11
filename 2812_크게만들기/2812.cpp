#include <bits/stdc++.h>
using namespace std;

int n, k;
char s[500002];

void getInput() {
    cin >> n >> k;
    cin >> s;

}
void Solve() {
    int i, j;
    stack<char> Stk;
    vector<char> Vec;
    Stk.push(s[0]);

    for (i=1; i<n; i++) {
        while (!Stk.empty() && k!=0) {
            if (s[i] > Stk.top()) {
                Stk.pop();
                k--;
            }
            else {
                break;
            }
        }
        if (k==0) break;
        Stk.push(s[i]);
    }

    if (k!=0) {
        for (int i=0; i< k; i++) {
            Stk.pop();
        }
    }

    while (!Stk.empty()) {
        Vec.push_back(Stk.top());
        Stk.pop();
    }


    for (int i = Vec.size()-1; i>=0; i--) {
        cout << Vec[i];
    }


    if (k==0) {
        for (j=i; j<n; j++) {
            cout << s[j];
        }
    }


}
int main() {
    getInput();
    Solve();
    return 0;

}