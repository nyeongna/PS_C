#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

/*
    삽입, 삭제가 빠른 "연결 리스트(list)" STL을 써야한다. (동적 배열 vector로 풀면 시간초과)

    조심해야 할 점!
    list.erase(it) 부분에서, cursor로 특정 위치 iterator를 가지고 놀때 특정 원소를 erase해버리면 cursor위치를 단순히 ++ 하면 안된다.
    ## list.erase(it)의 return value가 다음 element의 위치이므로 ##

    if (cursor != List.begin()) {
            cursor= List.erase(--cursor);
    }
    로 짜야하고

    if (cursor != List.begin()) {
            List.erase(--cursor);
            cursor++;
    }
    이렇게 짜면 오류가 난다. return 받지 않고 erase 된 순간 cursor의 위치는 미묘(?)해진다.
*/

string s, a, b;
list<char> List;
int n;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> s >> n;
    int i, j;
    for (i = 0; i < s.size(); i++) {
        List.push_back(s[i]);
    }
    auto cursor = List.end();

    for (i = 1; i <= n; i++) {
        cin >> a;
        if (a == "P") {
            cin >> b;
            List.insert(cursor, b[0]);
        }
        else if (a == "L") {
            if (cursor != List.begin()) {
                cursor--;
            }
        }
        else if (a == "D") {
            if (cursor != List.end()) {
                cursor++;
            }
        }
        else if (a == "B") {
            if (cursor != List.begin()) {
                cursor--;
                cursor = List.erase(cursor);
                //cursor++;
            }
        }
        // cout << *cursor << endl;
        // for (auto i : List) {
        //     cout << i << " ";
        // }
        //     cout << endl;
        //cout << *cursor << endl;
    }

    for (auto& i : List) {
        cout << i;
    }


    return 0;
}