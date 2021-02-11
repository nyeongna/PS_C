#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int
#define INT_INF 1000000000

int n;
vector<pair<int,int> > pillars;

void getInput() {
    cin >> n;
    int loc, h;
    for(int i=0; i<n; i++) {
        cin >> loc >> h;
        pillars.push_back({loc, h});
    }
    sort(pillars.begin(), pillars.end());
}
void Solve() {
    int i, j, ans = 0;
    //int max_height=pillars[0].second;
    int max_location = 0;
    
    int cur_loc = pillars[0].first;
    int cur_height = pillars[0].second;
    for(i=0; i<n; i++) {
        if (pillars[i].second >= cur_height) {
            ans += cur_height *(pillars[i].first - cur_loc );
            cur_height = pillars[i].second;
            cur_loc = pillars[i].first;
            max_location = i;
        }
    }
    cur_loc = pillars[pillars.size()-1].first;
    cur_height = pillars[pillars.size()-1].second;
    for(i=pillars.size()-1; i>=max_location; i--) {
        if (pillars[i].second >= cur_height) {
            ans += cur_height * (cur_loc - pillars[i].first);
            cur_height = pillars[i].second;
            cur_loc = pillars[i].first;
            
        }
    }
    ans += pillars[max_location].second;
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    getInput();
    Solve();
    return 0;
}