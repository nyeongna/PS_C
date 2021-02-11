#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 10007

int n, k;
long long dp[1001][1001];

int F(int n, int k) {
    if (k==0) return 1;
    if (k==1) return n;
    if (n==k) return 1;
    if (n < k) return 0;
    if (dp[n][k]!=0) return dp[n][k];

    return dp[n][k] = (F(n-1, k-1)%MOD + F(n-1, k)%MOD)%MOD;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> k;
    int i, j;
    
    cout << F(n,k) << endl;

    return 0;
}