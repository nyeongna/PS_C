#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    char s[101];
    cin >> s;

    stack<char> Stk;
    /*
        1. �ǿ�����(operand) �ٷ� ���
        2. �������� ��� top()���� �켱������ "��"�ų� �Ȱ��ٸ� push �Ѵ� (LIFO �̹Ƿ� �켱������ ������ ���� ���Ǿ���ϹǷ� ���߿� �ִ´�)
                        top()���� �켱������ "��"�ų� �Ȱ����� ������ pop() �Ѵ�. (�켱���� ���� �͵��� �̸� ���� ����ϰ����ش�)
        3. ���� ��ȣ "(" �� ��� push()
        4. �ݴ� ��ȣ ")" �� ��� Stk���� ���� ��ȣ�� ���Ë����� pop() �Ѵ�.
        5. ���ڿ� ���� ���� �ߴٸ� ������ pop()�Ѵ�. (stack�̹Ƿ� �켱������ ���� ������ ���´�)
    */
    for(i=0; i< strlen(s); i++) {
        // �ǿ�����(operand) �� ���
        if (s[i] >= 'A' && s[i] <= 'Z') {
            cout << s[i];
        }
        // �������ϰ�� + -
        else if (s[i] == '+' || s[i] == '-') {
            while (!Stk.empty() && Stk.top() != '(') {
                cout << Stk.top();
                Stk.pop();
            }
            Stk.push(s[i]);
        }
        // * , /
        else if (s[i] == '*' || s[i] == '/') {
            while (!Stk.empty() && Stk.top() != '(' &&  Stk.top() != '+' && Stk.top() != '-') {
                cout << Stk.top();
                Stk.pop();
            }
            Stk.push(s[i]);
        }
        else if (s[i]=='(') {
            Stk.push('(');
        }
        else if (s[i]==')') {
            while (!Stk.empty() && Stk.top() != '(' ) {
                cout <<Stk.top();
                Stk.pop();
            }
            Stk.pop();
        }
    }
    while (!Stk.empty()) {
        cout << Stk.top();
        Stk.pop();
    }
    return 0;
}