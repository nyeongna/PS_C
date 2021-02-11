#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

/*
    �׸��� �����̴�.
    �� ������ ���� "������ �ִ�"�� ���϶�� �Ѵ�.
    �׸���� ���� "���� ū", "���� ��", "���� ����"�� ���϶�� ���� ����. (������ �ʼ��� ��)

    1. ���� ������ �������� ����
    2. ���� ���������� �ش� ������ �ִ��� �ʰ� �ϴ� ��¥�� ������ ��.(4�ϱ����� 4->3->2->1 ��¥������ �˻�)
*/

int N;
int visit[1001];

struct Assignment {
    int day, point;
    bool operator<(const Assignment& b) const {
        if (point == b.point) return day < b.day;
        return point > b.point;
    }
};

vector<Assignment> a;
void getInput() {
    cin >> N;
    int i, j, day, score;
    for (i = 0; i < N; i++) {
        cin >> day >> score;
        a.push_back({ day, score });
    }
    sort(a.begin(), a.end());
    // cout << endl;
    // for(i=0; i<N; i++) {
    //     cout << a[i].day << " " << a[i].point << endl;
    // }
    // cout << endl;
}

void Solve() {
    int i, j, total = 0;
    for (i = 0; i < N; i++) {
        int d = a[i].day;
        for (j = d; j >= 1; j--) {
            if (visit[j] == 0) {
                visit[j] = a[i].point;
                total = total + a[i].point;
                break;
            }
        }
    }
    cout << total << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    getInput();
    Solve();


    return 0;
}