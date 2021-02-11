#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

int n;
lld dp[1001];

lld F(int n) {
    if (dp[n]!=0) return dp[n];
    if (n==2) return 2;
    if (n==1) return 1;
    
    return dp[n] = (F(n-1)%10007 + F(n-2)%10007) % 10007;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    cout << F(n) << endl;

    return 0;
}