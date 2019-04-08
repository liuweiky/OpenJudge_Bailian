#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

#define MAX_N 128
#define MAX_M 128

using namespace std;

struct device
{
    int band, price;
};

vector<device> devs[MAX_N];
int T, N;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);

        for (int i = 1; i <= N; i++)
        {
            int m;
            scanf("%d", &m);
            while (m--)
            {
                device d;
                scanf("%d %d", &d.band, &d.price);
                devs[i].push_back(d);
            }

        }

        double ans = -1;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j < devs[i].size(); j++)
            {
                device d = devs[i][j];

                int total_pric = d.price;
                bool can_be_min = true;

                for (int p = 1; p <= N; p++)
                {
                    if (p == i)
                        continue;
                    int min_price = INT_MAX;
                    for (int q = 0; q < devs[p].size(); q++)
                    {
                        if (devs[p][q].band < d.band)
                            continue;
                        min_price = min(min_price, devs[p][q].price);
                    }
                    if (min_price == INT_MAX)
                    {
                        can_be_min = false;
                        break;
                    }
                    total_pric += min_price;
                }

                if (can_be_min)
                    ans = max(ans, (double) d.band / total_pric);
            }
        }

        printf("%.3f\n", ans);
        for (int i = 1; i <= N; i++)
            devs[i].clear();
    }
    return 0;
}
