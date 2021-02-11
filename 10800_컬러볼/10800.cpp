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
        // size와 color 모두 같은 공이 나올수도 있으므로 color에 대해서도 정렬을 해야한다.
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

        //현재까지 쌓인 total 에서 같은 color면 빼고 같은 size면 또 뺀다.
        ans[idx] = total - C[color] - S[size];
        // 현재까지 나온 color에 대한 정보를 쌓아준다.
        C[color] += size;
        // 현재까지 나온 size에 대한 정보를 쌓아준다.
        S[size] += size;
        // 현재까지 나온 모든 size를 더해준다.
        total += size;

        // size와 color모두 똑같은 공이 나왔으면 위에서 C , S 두번 빼면 안되고 한번만 빼야한다.
        // 따라서 이전 공과 같은 수치를 넣어준다.
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