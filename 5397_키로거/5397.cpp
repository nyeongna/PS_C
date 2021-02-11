#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

int n;
string input;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int i, j;

    cin >> n;
    while(n--) {
        cin >> input;
        list<char> s;
        auto cursor=s.end();

        for(i=0; i<input.size(); i++) {
            if (input[i] == '<') {
                if (cursor!=s.begin()) cursor--;
            }
            else if (input[i] == '>') {
                if (cursor!= s.end()) cursor++;
            }
            else if (input[i] == '-') {
                if (cursor!=s.begin()) {
                    cursor = s.erase(--cursor);
                }
            }
            else {
                s.insert(cursor, input[i]);
            }
        }
        
        for(auto i=s.begin(); i != s.end(); i++) {
            cout << *i;
        }
        cout << endl;
    }
    return 0;
}