/*
    https://yabmoons.tistory.com/288
    ������ �̵��� ��ĭ��ĭ�� �� ��� �־��� ��� ������(10^4)���� * �ӵ�(10^3) * ���ÿ� �̵�Ƚ��(10^2) = 10^9 �� �ð��ʰ��� ��
    ������ ������ �̵�Ƚ��(1000)�� �ּ�ȭ ��Ű�� ���̴�.

    1. ������ �ӷ��� 100�϶� ��ĭ��ĭ �����̸� �����̴�.
    2. �ּ�ȯ���� �����̸鼭 100�����ΰͰ� ���� ����� ������.
    3. ���� �����Ⱑ ���� �������� ������ �����ٸ� ���� ��ġ�� �ٽ� ������� (r-1)*2 �� �����̸� �ȴ�.
    4. ���� ��� �ӷ�(1~1000)�� ���ؼ� �ִ� (r-1)*2���� �����̸� ����� �� �� �ִ�.
    5. ���� �ӵ��� 100�̰� c=5�� "100 % (c-1)*2 = 4"�̹Ƿ� �����Ⱑ ���� �ڸ����� 4��ŭ ������ �ڸ��� 100������ �ڸ��� ���ٴ� ��
    6. ���ӵ��� ȹ�������� �پ���! (100 --> �ִ� 8�� �����̹Ƿ�)
*/
#include <bits/stdc++.h>
using namespace std;

int graph[102][102];
int r, c, m;

typedef struct Shark
{
    // move 0�̸� ���� �ȿ����� ������
    // move 1�̸� ������ ���� ������
    int x, y, s, d, z, move;
} Shark;

vector<Shark> shark_list[102][102];
//vector<Shark> tmp[102][102];

int x_dir[] = {0, -1, 1, 0, 0};
int y_dir[] = {0, 0, 0, 1, -1};

int total = 0;

void getInput()
{
    cin >> r >> c >> m;
    int i, j;
    int x, y, s, d, z;

    for (i = 1; i <= m; i++)
    {
        cin >> x >> y >> s >> d >> z;
        shark_list[x][y].push_back({x, y, s, d, z, 0});
    }
}

int Reverse_Dir(int dir)
{
    if (dir == 1)
        return 2;
    if (dir == 2)
        return 1;
    if (dir == 3)
        return 4;
    if (dir == 4)
        return 3;
    return 0;
}

void Move(int &x, int &y, int speed, int &dir)
{
    if (dir >= 1 && dir <= 2)
    {
        speed = speed % ((r - 1) * 2);
    }
    else
        speed = speed % ((c - 1) * 2);

    while (speed != 0)
    {
        int dx = x + x_dir[dir];
        int dy = y + y_dir[dir];
        // ���� �ε�ġ�� ��
        if (dx >= 1 && dx <= r && dy >= 1 && dy <= c)
        {
            x = x + x_dir[dir];
            y = y + y_dir[dir];
            speed--;
            //cout << x << " " << y << " " << speed << " " << dir << endl;
        }
        // ���� �ε�ģ�ٸ�
        else
        {
            dir = Reverse_Dir(dir);
            x = x + x_dir[dir];
            y = y + y_dir[dir];
            speed--;
            //cout << x << " " << y << " " << speed << " " << dir << endl;
        }
    }
}

void Solve()
{
    int fisher_loc = 0;
    int i, j, k;
    while (1)
    {

        // ���ÿ��� ���������� 1ĭ �����δ�.
        fisher_loc = fisher_loc + 1;
        //cout << fisher_loc << endl;

        if (fisher_loc == c + 1)
        {
            cout << total << endl;
            return;
        }

        // ���� ����� �� ��´�.
        for (i = 1; i <= r; i++)
        {
            // ���ÿ��� ��ġ�� "��"�� �����Ⱑ �����ϸ� ��´�.
            if (shark_list[i][fisher_loc].size() != 0)
            {
                total = total + shark_list[i][fisher_loc][0].z;
                shark_list[i][fisher_loc].pop_back();
                break;
            }
        }

        // �� �̵��Ѵ�.
        for (i = 1; i <= r; i++)
        {
            for (j = 1; j <= c; j++)
            {
                // �� ĭ�� �� ������ continue
                if (shark_list[i][j].size() == 0)
                    continue;

                // �̹� �������� �����⿴���� continue
                if (shark_list[i][j][0].move == 1)
                    continue;

                int x = i;
                int y = j;
                int s = shark_list[i][j][0].s;
                int d = shark_list[i][j][0].d;
                int z = shark_list[i][j][0].z;

                // �̵��Ѵ�
                Move(x, y, s, d);

                // ���� �ڸ����� �ִ� shark ������ ���ش�.
                shark_list[i][j].erase(shark_list[i][j].begin());

                // ���ο� �ڸ��� shark ������ �߰��Ѵ�.
                shark_list[x][y].push_back({x, y, s, d, z, 1});
            }
        }

        // �� ��ҿ� �θ��� �̻� ������ ��ƸԴ´�.
        for (i = 1; i <= r; i++)
        {
            for (j = 1; j <= c; j++)
            {
                if (shark_list[i][j].size() >= 2)
                {
                    int max_size = -2147000000;
                    int new_x, new_y, new_s, new_d;
                    // ����ū ������ ����� ���Ѵ�.
                    // ���� ū �����⸦ ������ ������ �����⸦ ���ش�.
                    for (k = 0; k < shark_list[i][j].size(); k++)
                    {
                        if (max_size < shark_list[i][j][k].z)
                        {
                            max_size = shark_list[i][j][k].z;
                            new_x = i;
                            new_y = j;
                            new_s = shark_list[i][j][k].s;
                            new_d = shark_list[i][j][k].d;
                        }
                    }
                    shark_list[i][j].clear();
                    shark_list[i][j].push_back({new_x, new_y, new_s, new_d, max_size, 0});
                }
                // 안녕하세요
                else if (shark_list[i][j].size() == 1)
                {
                    shark_list[i][j][0].move = 0;
                }
            }
        }
    }
}

int main()
{
    
    getInput();
    Solve();
    return 0;
}