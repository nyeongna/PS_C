#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

/*
    ����, ������ ���� "���� ����Ʈ(list)" STL�� ����Ѵ�. (���� �迭 vector�� Ǯ�� �ð��ʰ�)

    �����ؾ� �� ��!
    list.erase(it) �κп���, cursor�� Ư�� ��ġ iterator�� ������ � Ư�� ���Ҹ� erase�ع����� cursor��ġ�� �ܼ��� ++ �ϸ� �ȵȴ�.
    ## list.erase(it)�� return value�� ���� element�� ��ġ�̹Ƿ� ##

    if (cursor != List.begin()) {
            cursor= List.erase(--cursor);
    }
    �� ¥���ϰ�

    if (cursor != List.begin()) {
            List.erase(--cursor);
            cursor++;
    }
    �̷��� ¥�� ������ ����. return ���� �ʰ� erase �� ���� cursor�� ��ġ�� �̹�(?)������.
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