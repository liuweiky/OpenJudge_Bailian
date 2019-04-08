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

bool cmp(device& d1, device& d2)
{
    return d1.price < d2.price;
}

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
            sort(devs[i].begin(), devs[i].end(), cmp);
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
                    int q = 0;
                    while (q < devs[p].size() && devs[p][q].band < d.band)
                        q++;
                    if (q == devs[p].size())
                    {
                        can_be_min = false;
                        break;
                    }
                    total_pric += devs[p][q].price;
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
