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

    // 'i' 번 방에 대한 정보를 Rooms 벡터에 추가해줍니다.
    for (i = 1; i <= N; i++) {
        cin >> t >> a >> h;
        Rooms.push_back({ t, a, h });
    }

    // r을 최대한 큰 수로 초기화, l을 max_hp의 최저인 1로 초기화
    long long int l = 1, r = 1e18;
    long long int ans;
    
    while (l <= r) {
        // 이분탐색으로 max_hp를 찾습니다.
        max_hp = (l + r) / 2;
        // cur_hp는 max_hp로 처음에 초기화 시켜줍니다 (던전 진입 전)
        cur_hp = max_hp;
        // 용사 공격력도 초기 공격력으로 초기화 시켜줍니다.
        w_atk = init_w_atk;
        for (i = 0; i < Rooms.size(); i++) {
            long long int t = Rooms[i].t;
            long long int atk = Rooms[i].a;
            long long int hp = Rooms[i].h;
            // 몬스터를 만날 시
            if (t == 1) {
                long long int cnt;
                // 용사의 마지막 cur_hp를 O(1) 시간으로 계산합니다.
                if (hp % w_atk==0) cnt = hp / w_atk;
                else cnt = hp / w_atk + 1;
                cur_hp = cur_hp - atk * (cnt-1);
                // 용사의 cur_hp가 0 이하로 되었다면 전투중 죽은 것.
                if (cur_hp <= 0) {
                    break;
                }
            }

            // 포션 일 시
            else {
                // 현재 hp가 회복, 공격력 증가, 단 max_hp 초과되지는 않음.
                cur_hp = cur_hp + hp;
                if (cur_hp >= max_hp) cur_hp = max_hp;
                w_atk = w_atk + atk;
            }

        }
        
        // max_hp가 충분 했다면 (즉 모든 몬스터를 죽이고도 살아남았다면)
        // ans에 max_hp를 저장해줌
        if (cur_hp > 0) {
            ans = max_hp;
            r = max_hp - 1;
        }
        // cur_hp가 0이하라면 죽은 것이므로 l = max_hp + 1해서 다시 이분탐색 시작.
        else {
            l = max_hp + 1;
        }

    }

    cout << ans << endl;
    // cout << l << " " << r << " " << max_hp << " " << cur_hp << endl;

    return 0;
}