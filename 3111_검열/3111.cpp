#include <bits/stdc++.h>
using namespace std;

string target;
string s;
deque<char> DQ;

void getInput() {
    cin >> target;
    cin >> s;
}
void Solve() {
    int i, j;
    for (i = 0; i < s.size(); i++) {
        DQ.push_back(s[i]);
    }
    i = 0, j = s.size() - 1;

}
int main() {
    getInput();
    Solve();
    return 0;

}