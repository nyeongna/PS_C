#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n;
int dp[100001];

int F(int n) {
    if (n==1) return 1;
    if (n==2) return 2;
    if (n==3) return 3;
    if(dp[n]!=n) return dp[n];
    int i;
    int ans = dp[n];
    for(i=1; i<=sqrt(n); i++) {
        ans = min(ans, F(n-i*i)+1);
    }
    return dp[n]=ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int i, j;
    cin >> n;
    for(i=0; i<=n; i++) {
        dp[i] = i;
    }
    cout << F(n) << endl;

    return 0;
}