#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 10007

int n;
int dp[1001];

int F(int n) {
    if (dp[n]!=0) return dp[n];
    if (n==1) return 1;
    if (n==2) return 3;

    return dp[n] = (F(n-1)%MOD + F(n-2) * 2 %MOD)%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    cout << F(n) << endl;
    return 0;
}