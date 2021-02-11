#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int n;
int C[200001];
int S[2001];
int ans[200001];

struct Ball {
    int size, color, idx;
    bool operator<(const Ball& b) const {
        // size�� color ��� ���� ���� ���ü��� �����Ƿ� color�� ���ؼ��� ������ �ؾ��Ѵ�.
        if (size == b.size) return color < b.color;
        return size < b.size;
    }
};

vector<Ball> Balls;

void getInput() {
    cin >> n;
    int color, size, i;
    for (i = 0; i < n; i++) {
        cin >> color >> size;
        Balls.push_back({ size, color, i });
    }
    sort(Balls.begin(), Balls.end());
}
void Solve() {
    int i, size, color, idx;
    int total = 0;
    for (i = 0; i < n; i++) {
        size = Balls[i].size;
        color = Balls[i].color;
        idx = Balls[i].idx;

        //������� ���� total ���� ���� color�� ���� ���� size�� �� ����.
        ans[idx] = total - C[color] - S[size];
        // ������� ���� color�� ���� ������ �׾��ش�.
        C[color] += size;
        // ������� ���� size�� ���� ������ �׾��ش�.
        S[size] += size;
        // ������� ���� ��� size�� �����ش�.
        total += size;

        // size�� color��� �Ȱ��� ���� �������� ������ C , S �ι� ���� �ȵǰ� �ѹ��� �����Ѵ�.
        // ���� ���� ���� ���� ��ġ�� �־��ش�.
        if (i != 0 && size == Balls[i - 1].size && color == Balls[i - 1].color) {
            ans[idx] = ans[Balls[i - 1].idx];
        }
    }
    for (i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    getInput();
    Solve();
    return 0;
}