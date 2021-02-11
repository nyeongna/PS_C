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
    cout << endl;
    stack<pair<int,int>> Stk;
    for(i=0; a[i].first <= max_loc; i++) {
        if (Stk.empty()) {
            Stk.push({a[i].first, a[i].second});
        }
        else if (a[i].second >= Stk.top().second) {
            area = area + Stk.top().second * (a[i].first - Stk.top().first);
            Stk.push({a[i].first, a[i].second});
        }
    }
    i--;
    cout << area << endl;
    while(!Stk.empty()) Stk.pop();

    for(j=n-1; j>=i; j--) {
        if (Stk.empty()) {
            Stk.push({a[j].first, a[j].second});
        }
        else if (a[j].second >= Stk.top().second) {
            area = area + Stk.top().second * (Stk.top().first - a[j].first);
            Stk.push({a[j].first, a[j].second});
        }
    }
    area = area + max_height;
    cout << area << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    getInput();
    Solve();
}