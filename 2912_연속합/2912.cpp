#include <bits/stdc++.h>
using namespace std;

int dp[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a;
    int i, num;
    for(i=0; i<n; i++) {
        cin >> num;
        a.push_back(num);
    }
    int local_num = 0;
    int max_num = a[0];
    // for(i=0; i<n; i++) {
    //     local_num = max(a[i], a[i]+local_num);
    //     max_num = max(local_num, max_num);
    // }
    // max_num=-2147000000;
    dp[0]=a[0];
    for(i=1; i<n; i++) {
        dp[i] = max(dp[i-1]+a[i],a[i]);
        max_num=max(max_num, dp[i]);
    }
    cout << max_num << endl;
    return 0;
}