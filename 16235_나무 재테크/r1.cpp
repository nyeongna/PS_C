#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int x, y, z;

int x_dir[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int y_dir[] = {0, 1, 0, -1, 1, 1, -1, -1};

// 땅마다 양분이 더해지는 정보가 담겨있다
int energy[11][11];

// 땅에 몇개의 나무가 심어져 있는지 담겨있다.
vector<int> tree_list[11][11];

// 현재 땅의 양분이 담겨있다.
int ground[11][11];

// 죽은 나무 정보가 담겨져있다.
vector<int> dead_list[11][11];

void getInput()
{
    cin >> N >> M >> K;
    int i, j;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            cin >> energy[i][j];
            ground[i][j] = 5;
        }
    }
    for (i = 1; i <= M; i++)
    {
        cin >> x >> y >> z;
        tree_list[x][y].push_back(z);
    }
}

void printGround()
{
    int i, j;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            cout << ground[i][j] << " ";
        }
        cout << endl;
    }
}

void Solve()
{
    int i, j, k, year = 0;
    int ans = 0;
    while (1)
    {

        if (year == K)
        {
            for (i = 1; i <= N; i++)
            {
                for (j = 1; j <= N; j++)
                {
                    if (tree_list[i][j].size() != 0)
                    {
                        ans = ans + tree_list[i][j].size();
                    }
                }
            }
            cout << ans << endl;
            return;
        }

        // 봄
        for (i = 1; i <= N; i++)
        {
            for (j = 1; j <= N; j++)
            {

                if (tree_list[i][j].size() == 0)
                    continue;

                sort(tree_list[i][j].begin(), tree_list[i][j].end());

                for (k = 0; k < tree_list[i][j].size();)
                {

                    // 땅에 양분이 충분하다면
                    if (ground[i][j] >= tree_list[i][j][k])
                    {
                        ground[i][j] -= tree_list[i][j][k];
                        tree_list[i][j][k]++;
                        k++;
                    }

                    // 땅에 양분이 충분하지 않으니 나무를 죽인다.
                    else
                    {
                        dead_list[i][j].push_back(tree_list[i][j][k]);
                        tree_list[i][j].erase(tree_list[i][j].begin() + k);
                    }
                }
            }
        }

        // 여름
        for (i = 1; i <= N; i++)
        {
            for (j = 1; j <= N; j++)
            {

                if (dead_list[i][j].size() == 0)
                    continue;

                int size = dead_list[i][j].size() - 1;

                for (k = size; k >= 0; k--)
                {
                    ground[i][j] += dead_list[i][j][k] / 2;
                    dead_list[i][j].pop_back();
                }
                //dead_list[i][j].clear();
            }
        }

        // 가을
        for (i = 1; i <= N; i++)
        {
            for (j = 1; j <= N; j++)
            {

                if (tree_list[i][j].size() == 0)
                    continue;

                for (k = 0; k < tree_list[i][j].size(); k++)
                {
                    if (tree_list[i][j][k] % 5 == 0)
                    {
                        for (int a = 0; a < 8; a++)
                        {
                            int dx = i + x_dir[a];
                            int dy = j + y_dir[a];
                            if (dx < 1 || dx > N || dy < 1 || dy > N)
                                continue;
                            tree_list[dx][dy].push_back(1);
                        }
                    }
                }
            }
        }

        // 겨울
        for (i = 1; i <= N; i++)
        {
            for (j = 1; j <= N; j++)
            {
                ground[i][j] += energy[i][j];
            }
        }
        year++;
    }
}

int main()
{
    getInput();
    Solve();
    return 0;
}