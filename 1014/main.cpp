#include <cstdio>
#include <algorithm>

#define MAX_N 20480

using namespace std;

int marbles[MAX_N];
int N, sum, half, cs = 1;
int dp[MAX_N * 6];

int main()
{
    N = 0, sum = 0;
    for (int i = 1; i <= 6; i++)
    {
        int cnt;
        scanf("%d", &cnt);
        sum += cnt * i;

        for (int j = 1; j <= cnt; j *= 2)
        {
            marbles[N++] = j * i;
            cnt -= j;
        }

        if (cnt > 0)
            marbles[N++] = cnt * i;

        /*while (cnt--)
            marbles[N++] = i;*/
    }

    while (N != 0)
    {
        if (sum % 2 == 1)
        {
            printf("Collection #%d:\nCan't be divided.\n\n", cs);
            goto L1;
        }
        half = sum / 2;
        fill_n(dp, sum + 32, 0);
        for (int i = 0; i < N; i++)
            for (int m = half; m >= marbles[i]; m--)
                dp[m] = max(dp[m], dp[m - marbles[i]] + marbles[i]);
        if (dp[half] == half)
            printf("Collection #%d:\nCan be divided.\n\n", cs);
        else
            printf("Collection #%d:\nCan't be divided.\n\n", cs);
L1:
        cs++;
        N = 0, sum = 0;
        for (int i = 1; i <= 6; i++)
        {
            int cnt;
            scanf("%d", &cnt);
            sum += cnt * i;

            for (int j = 1; j <= cnt; j *= 2)
            {
                marbles[N++] = j * i;
                cnt -= j;
            }

            if (cnt > 0)
                marbles[N++] = cnt * i;

            /*while (cnt--)
                marbles[N++] = i;*/
        }
    }

    return 0;
}
