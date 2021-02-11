#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b, op;
    int i, j;
    cin >> a >> op >> b;
    if (op=="*") {
        cout << 1;
        for (i=1; i<a.size(); i++) {
            cout << 0;
        }
        for (i=1; i<b.size(); i++) {
            cout << 0;
        }
    }
    else {
        int as = a.size();
        int bs = b.size();

        if (as==bs) {
            cout << 2;
            for(i=1; i<as; i++) {
                cout <<a[i];
            }
        }
        else {
            cout << 1;
            for (i=1; i< abs(as-bs); i++) {
                cout << 0;
            }
            for (i=0; i < (as > bs ? as : bs); i++) {
                cout << (as>bs? b[i] :a[i]);
            }

        }
    }
}