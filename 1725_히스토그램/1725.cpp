#include <bits/stdc++.h>
using namespace std;

int n;
int graph[100001];

void getInput() {
    cin >> n;
    int i;
    for(i=1; i<=n; i++) {
        cin >> graph[i];
    }
}
void Solve() {
    int i, j, max_h = -2147000000, max_w = 0;
    int h = graph[i];
    for(i=2; i<=n; i++) {
        if (graph[i] < h)
        {
            max_w = 1;
            h = graph[i];
        }
        else 
        {
            
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    getInput();
    Solve();
    return 0;
}