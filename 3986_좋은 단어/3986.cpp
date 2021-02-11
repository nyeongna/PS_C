#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int
#define INT_INF 1000000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int i,j;
    string words;
    int ans=0;
    for(i=0; i<n; i++) {
        cin >> words;
        stack<char> Stk;
        for(j=0; j<words.size(); j++) {
            if (Stk.empty()) {
                Stk.push(words[j]);
            }
            else if (Stk.top() == words[j]) {
                Stk.pop();
            }
            else {
                Stk.push(words[j]);
            }
        }
        if (Stk.empty()) ans++;
    }
    cout << ans << endl;
    return 0;
}