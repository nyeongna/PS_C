#include <bits/stdc++.h>
using namespace std;

pair<int,int> a[1002];
int n, w, h;
int max_height=0;
int max_loc=0;
void getInput() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a+n);
    for(int i=0; i<n; i++) {
        if (a[i].second > max_height) {
            max_height = a[i].second;
            max_loc = a[i].first;
        }
    }
}
void Solve() {
    
    int i, j, area=0;
    stack<pair<int,int>> Stk;

    int left_loc=a[0].first, left_h=a[0].second;

    for(i=0; i<n; i++) {
        if (i==0) Stk.push({a[i].first, a[i].second});
        if (a[i].second > Stk.top().second) {
            left_loc = a[i].first;
            left_h = a[i].second;
            area += Stk.top().second * (a[i].first - Stk.top().first);
            Stk.push({a[i].first, a[i].second});
        }
    }
    
    int right_loc = a[n-1].first, right_h=a[n-1].second;
    for(i=n-1; i>=0; i--) {
        if (i==n-1) Stk.push({a[i].first, a[i].second});
        if (a[i].second > Stk.top().second) {
            right_loc = a[i].first;
            right_h = a[i].second;
            area += Stk.top().second * (Stk.top().first- a[i].first);
            Stk.push({a[i].first, a[i].second});
        }
    }

    area += (right_loc - left_loc + 1) * left_h;
    
    cout << area << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    getInput();
    Solve();
}