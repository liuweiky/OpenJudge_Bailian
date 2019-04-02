#include <cstdio>
#include <algorithm>

#define MAX_N 128

using namespace std;

int stks[MAX_N];
bool vis[MAX_N];
int N, total_len = 0, ans = 0;
bool canbe = false;

void dfs(int len, int sum, int cnt, int bg)
{
    if (len == sum && cnt == N)
    {
        canbe = true;
        return;
    }
    if (len == sum)
    {
        sum = 0;
        bg = N;
    }
    for (int i = bg; i >= 1; i--)
    {
        if (vis[i] || sum + stks[i] > len || ((i < N) && !vis[i + 1] && stks[i] == stks[i + 1]))
            continue;
        vis[i] = true;
        dfs(len, sum + stks[i], cnt + 1, i - 1);
        vis[i] = false;
        if (canbe || sum == 0)
            return;
    }
}

int main()
{
    scanf("%d", &N);

    while (N != 0)
    {
        total_len = 0;
        canbe = false;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &stks[i]);
            total_len += stks[i];
        }
        sort(stks + 1, stks + 1 + N);

        for (int i = stks[N]; i <= total_len; i++)
        {
            if (total_len % i != 0)
                continue;
            fill_n(vis, MAX_N, false);
            dfs(i, 0, 0, N);
            if (canbe)
            {
                printf("%d\n", i);
                break;
            }
        }
        scanf("%d", &N);
    }

    return 0;
}
