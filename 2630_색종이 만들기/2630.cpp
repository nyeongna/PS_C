#include <bits/stdc++.h>
using namespace std;

int n;
int paper[129][129];

/*
    ��������
    �����Ҷ� ���������� ��� �ϳĿ� ���� ������! ��������.
*/

void getInput() {
    cin >> n;
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> paper[i][j];
        }
    }
}
int color[2];


// x == ���������� x, y == ���������� y
// n == Ȯ���ؾ��� �Ÿ�
void Divide(int x, int y, int n) {
    int i, j, flag = 1;
    // i < x+n ���� �˻��Ѵ�
    for (i = x; i < x + n; i++) {
        // j < y + n���� �˻��Ѵ�.
        for (j = y; j < y + n; j++) {
            if (paper[x][y] != paper[i][j]) {
                flag = 0;
                break;
            }
        }
    }
    if (flag == 1) {
        color[paper[x][y]]++;
        return;
    }
    //���� ��
    Divide(x, y, n / 2);
    //������ ��
    Divide(x, y + n / 2, n / 2);
    //���� �Ʒ�
    Divide(x + n / 2, y, n / 2);
    //������ �Ʒ�
    Divide(x + n / 2, y + n / 2, n / 2);
}
void Print() {
    cout << color[0] << endl;
    cout << color[1] << endl;
}
int main() {
    getInput();
    // ���������� (x,y)��ǥ�κ��� n�Ÿ������� �˻��Ѵ�.
    Divide(1, 1, n);
    Print();

    return 0;
}