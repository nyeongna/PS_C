#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

int n,p;

void getInput() {
    cin >> n >> p;
}
stack<int> a[7];

void Solve() {
    int i, j, line, flat, cnt=0;
    for(i=0; i<n; i++) {
        cin >> line >> flat;
        if (a[line].empty()){
            a[line].push(flat);
            cnt++;
        }
        // 현재 해당 '줄'에 더 높은 음을 누르고 있다면
        else if (a[line].top() > flat) {
            while (!a[line].empty() && a[line].top() > flat) {
                a[line].pop();
                cnt++;  
            }
            if (a[line].empty() || a[line].top() != flat) {
                a[line].push(flat);
                cnt++;
            }
        }
        // 현재 해당 '줄'에 낮은 음만 있다면
        else if (a[line].top() < flat) {
            a[line].push(flat);
            cnt++;
        }
    }
    cout << cnt << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    getInput();
    Solve();
    return 0;
}