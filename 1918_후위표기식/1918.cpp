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
        1. 피연사자(operand) 바로 출력
        2. 연산자일 경우 top()보다 우선순위가 "높"거나 똑같다면 push 한다 (LIFO 이므로 우선순위가 높은게 먼저 계산되어야하므로 나중에 넣는다)
                        top()보다 우선순위가 "낮"거나 똑같으면 모조리 pop() 한다. (우선순위 높은 것들을 미리 빼서 계산하게해준다)
        3. 여는 괄호 "(" 일 경우 push()
        4. 닫는 괄호 ")" 일 경우 Stk에서 여는 괄호가 나올떄까지 pop() 한다.
        5. 문자열 끝에 도달 했다면 모조리 pop()한다. (stack이므로 우선순위가 높은 순으로 나온다)
    */
    for(i=0; i< strlen(s); i++) {
        // 피연산자(operand) 일 경우
        if (s[i] >= 'A' && s[i] <= 'Z') {
            cout << s[i];
        }
        // 연산자일경우 + -
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