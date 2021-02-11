#include <bits/stdc++.h>
using namespace std;

// dp[n]는 n에서 1로 갈 때 필요한 최소 횟수가 담겨져있음.
int dp[1000002];

int F(int n) {
    if (dp[n] != 0) return dp[n];
    if (n==1) return dp[1] = 0;

    int min_val = 2147000000;
    min_val = min(min_val, F(n-1) + 1);
    if (n%3==0) min_val = min(min_val, F(n/3)+1);
    if (n%2==0) min_val = min(min_val, F(n/2)+1);
    
    return dp[n] = min_val;
}
int main() {
    int n;
    cin >> n;

    int i;
    // DFS(n) 은 n에서 1로 갈 떄 필요한 최소 횟수
    cout << F(n);
    
    return 0;
}