#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

long long int MOD(int a, int b, int c) {
    if ( b == 1) return a % c;
    long long tmp = MOD(a, b/2, c);

    if (b % 2 ==0) {
        return tmp * tmp % c;
    }
    else {
        return tmp * tmp % c * a % c;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;

    cout << MOD(a,b,c) << endl;
    return 0;
}