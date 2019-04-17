#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <climits>

#define MAX_N 32
#define MAX_S 256

using namespace std;

int T, S, N;

int Ns[MAX_N];
bool mp[MAX_N];
int line_occupied[MAX_S];
bool feasible;

bool cmp(int& a, int& b)
{
    return a > b;
}

void dfs(int cnt)
{
    /*system("pause");
    printf("%d\n", cnt);
    for (int i = 1; i <= S; i++)
        printf("%d ", line_occupied[i]);
    printf("\n");*/
    if (cnt == N)
    {
        feasible = true;
        return;
    }

    bool dfs_flag = false;

    for (int i = 1; i <= N; i++)
    {
        if (i != 1 && dfs_flag && Ns[i] == Ns[i - 1])
            continue;
        if (!mp[i])
        {
            int j, k, min_line_occu = INT_MAX;
            for (j = 1; j + Ns[i] - 1 <= S; j++)
            {
                if (min_line_occu > line_occupied[j])
                {
                    k = j;
                    min_line_occu = line_occupied[j];
                }
            }
            bool can_fill = true;
            if (S - line_occupied[k] >= Ns[i])
            {
                for (j = k + 1; j < k + Ns[i]; j++)
                    if (line_occupied[j] != line_occupied[k])
                    {
                        can_fill = false;
                        break;
                    }
                if (can_fill)
                {

                    for (j = k; j < k + Ns[i]; j++)
                        line_occupied[j] += Ns[i];
                }
            }
            else
                continue;
            if (!can_fill)
                continue;

            mp[i] = true;
            dfs(cnt + 1);
            if (feasible)
                return;
            dfs_flag = true;
            mp[i] = false;
            for (j = k; k < j + Ns[i]; k++)
                line_occupied[k] -= Ns[i];
        }
        if (cnt == 0)
            return;
    }
}

int main()
{
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d", &S);
        scanf("%d", &N);
        int total_sz = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &Ns[i]);
            total_sz += Ns[i] * Ns[i];
        }
        if (S * S != total_sz)
        {
            printf("HUTUTU!\n");
            continue;
        }
        fill_n(line_occupied, S + 1, 0);
        fill_n(mp, N + 1, false);
        sort(Ns + 1, Ns + 1 + N, cmp);
        feasible = false;
        dfs(0);
        feasible ? printf("KHOOOOB!\n") : printf("HUTUTU!\n");
    }

    return 0;
}
