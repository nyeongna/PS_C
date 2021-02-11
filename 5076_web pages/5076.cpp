#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int
#define INT_INF 1000000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string line;
    while(1) {
        getline(cin, line);
        if (line[0] == '#') {
            break;
        }
        int i=0, j=0;
        stack<string> Stk;
        for(i=0; i<line.size(); i++) {
            // open tag
            string tmp="";
            if (line[i]=='<') {
                // close tag
                if (line[i+1] == '/') {
                    i = i + 2;
                    while (line[i] != '>') {
                        tmp += line[i];
                        i++;
                    }
                    if (Stk.size()==0 || Stk.top() != tmp) {
                        Stk.push("ab");
                        break;
                    }
                    if (Stk.top() == tmp) {
                        Stk.pop();
                    }
                }
                // open tag or self-closing tag or attribute
                else {
                    int blank=0, self=0;
                    while(1) {
                        // attribute
                        i++;
                        if (line[i] == '/' && line[i+1]=='>') self++;
                        if (line[i] == ' ') blank++;
                        if (line[i] == '>') break;
                        if (blank==0) {
                            tmp += line[i];
                        }
                    }
                    if (self==0) {
                        Stk.push(tmp);
                    }
                }
                
            }
        }
        if (Stk.size() == 0) {
            cout << "legal" << endl;
        }
        else cout << "illegal" << endl;
    }

    return 0;
}