#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    �׸���(Greedy) �����̴�.
    "�ּ��� ���ǽ�"�� ����ؼ� "��� ����"�� �����ϰ� �ؾ���.
    ���� "���� �ð�"�� �������� �����ؾ���.
    �� "������ �ð�"�� �������� �����ϸ� �ȵǴ��� �𸣰���....

    * ���� ������ ���� ������ ��(term)�� "�ּ�ȭ"�ؾ� "�ּ��� ���ǽ�"�� ����ؼ� ��� ������ ���� �� �ִ�.
    * ���� "���� �ð�"�� �������� �����Ѵ�....
    * "���� �ð�"�� �������� �ع����� �� ������ ������ �������� �𸣴ϱ� ������ ���δ�.
    * �ݷ�) (1,5), (2,3), (4,8), (6,7)
*/

int N;
struct Class {
    // s = ���� �ð�, t = ���� �ð�
    int s, t;
    bool operator<(const Class& b) const {
        if (t == b.t) return s < b.s;
        return t < b.t;
    }
};

// input �������� ������ class ����
vector<Class> a(200001);

void getInput() {
    cin >> N;
    int i, j;
    for (i = 0; i < N; i++) {
        cin >> a[i].s >> a[i].t;
    }
    sort(a.begin(), a.begin() + N);
    // for (i = 0; i < N; i++) {
    //     cout << a[i].s << " " << a[i].t << endl;
    // }
}

void Solve() {
    // ������ ���� �ð��� �������� �ϴ� min heap
    priority_queue<int, vector<int>, greater<int>> pQ;

    // ù��° ������ pQ�� push
    pQ.push(a[0].t);

    // ���ǽ� ������ '1'���� ����
    int i, j, cnt = 1;

    for (i = 1; i < N; i++) {
        //  [ pQ.top()�� a[i].s���� ũ�Ƿ� ] ���ο� ���ǽ��� ������ �ϴ� ��Ȳ
        if (pQ.top() > a[i].s) {
            pQ.push(a[i].t);
            cnt++;
        }
        //  [ pQ.top()�� a[i].s���� �۰ų� ] �����Ƿ� ���ǽ��� �� �� �� ����.
        else {
            pQ.pop();
            pQ.push(a[i].t);
        }
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    getInput();
    Solve();
    return 0;
}