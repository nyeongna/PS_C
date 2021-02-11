#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int x, y, z;
int graph[11][11];
int ground[11][11];
vector<int> tree_list[11][11];

int x_dir[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int y_dir[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);

    int i;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {

            sort(tree_list[i][j].begin(), tree_list[i][j].end());
        }
    }

    return 0;
}