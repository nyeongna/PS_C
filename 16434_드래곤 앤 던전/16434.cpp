#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000000
#define lld long long int

long long int init_w_atk;
long long int N, w_atk, t, a, h;
long long int max_hp, cur_hp;

struct Room {
    long long int t, a, h;
};

vector<Room> Rooms;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    cin >> init_w_atk;
    int i, j;

    // 'i' �� �濡 ���� ������ Rooms ���Ϳ� �߰����ݴϴ�.
    for (i = 1; i <= N; i++) {
        cin >> t >> a >> h;
        Rooms.push_back({ t, a, h });
    }

    // r�� �ִ��� ū ���� �ʱ�ȭ, l�� max_hp�� ������ 1�� �ʱ�ȭ
    long long int l = 1, r = 1e18;
    long long int ans;
    
    while (l <= r) {
        // �̺�Ž������ max_hp�� ã���ϴ�.
        max_hp = (l + r) / 2;
        // cur_hp�� max_hp�� ó���� �ʱ�ȭ �����ݴϴ� (���� ���� ��)
        cur_hp = max_hp;
        // ��� ���ݷµ� �ʱ� ���ݷ����� �ʱ�ȭ �����ݴϴ�.
        w_atk = init_w_atk;
        for (i = 0; i < Rooms.size(); i++) {
            long long int t = Rooms[i].t;
            long long int atk = Rooms[i].a;
            long long int hp = Rooms[i].h;
            // ���͸� ���� ��
            if (t == 1) {
                long long int cnt;
                // ����� ������ cur_hp�� O(1) �ð����� ����մϴ�.
                if (hp % w_atk==0) cnt = hp / w_atk;
                else cnt = hp / w_atk + 1;
                cur_hp = cur_hp - atk * (cnt-1);
                // ����� cur_hp�� 0 ���Ϸ� �Ǿ��ٸ� ������ ���� ��.
                if (cur_hp <= 0) {
                    break;
                }
            }

            // ���� �� ��
            else {
                // ���� hp�� ȸ��, ���ݷ� ����, �� max_hp �ʰ������� ����.
                cur_hp = cur_hp + hp;
                if (cur_hp >= max_hp) cur_hp = max_hp;
                w_atk = w_atk + atk;
            }

        }
        
        // max_hp�� ��� �ߴٸ� (�� ��� ���͸� ���̰� ��Ƴ��Ҵٸ�)
        // ans�� max_hp�� ��������
        if (cur_hp > 0) {
            ans = max_hp;
            r = max_hp - 1;
        }
        // cur_hp�� 0���϶�� ���� ���̹Ƿ� l = max_hp + 1�ؼ� �ٽ� �̺�Ž�� ����.
        else {
            l = max_hp + 1;
        }

    }

    cout << ans << endl;
    // cout << l << " " << r << " " << max_hp << " " << cur_hp << endl;

    return 0;
}