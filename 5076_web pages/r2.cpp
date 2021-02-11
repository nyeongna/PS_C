#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while(true) {
        string input;
        getline(cin, input);
        if (input == "#") break;
        stack<string> Stk;

        for (int i=0; i<input.size(); i++) {
            // start tag
            if (input[i]=='<' && input[i+1] != '/') {
                int start = i;
                int self = -1;
                i++;
                while (i < input.size() && input[i] != ' ' && input[i] != '>') {
                    i++;
                }
                //if (input[i] ==' ') self=1;
                //cout << i << " " << self << endl;
                if (self == -1 && input[i+1] != '/' && input[i+2] != '>') {
                    Stk.push(input.substr(start+1, i-start-1));
                    
                }
                
            }
            // close tag
            if (i+1 < input.size() && input[i] =='<' && input[i+1] =='/') {
                int start = i;
                while (i<input.size() && input[i] != '>') {
                    i++;
                }
                if (Stk.top() == input.substr(start+2, i-start-2)) {
                    Stk.pop();
                }
                else {
                    //cout << "illegal" << endl;
                    break;
                }
            }
        }
        if (Stk.empty()) {
            cout << "legal" << endl;
        }
        else {
            cout << "illegal" << endl;
        }
    }
    return 0;
}