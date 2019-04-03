#include <cstdio>
#include <cstring>

using namespace std;

int ans[32];

int main()
{
    memset(ans, -1, sizeof(ans));
    int k, m;
    scanf("%d", &k);
    while (k != 0)
    {
        if (ans[k] != -1)
        {
            printf("%d\n", ans[k]);
            scanf("%d", &k);
            continue;
        }
        bool flag;
        for (m = k + 1; ; m++)
        {
            flag = true;
            int p = 0;
            for (int i = 0; i < k; i++)
            {
                p = (p + m - 1) % (2 * k - i);
                if (p < k)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ans[k] = m;
                printf("%d\n", m);
                break;
            }
        }
        scanf("%d", &k);
    }

    return 0;
}
