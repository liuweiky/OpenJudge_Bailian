#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

#define UNKNOWN INT_MAX

int mp[128];
int N;

int main()
{
    scanf("%d", &N);

    while (N--)
    {
        fill_n(mp, 128, UNKNOWN);
        char lf[32], rg[32], info[12];

        for (int t = 0; t < 3; t++)
        {
            scanf("%s %s %s", lf, rg, info);
            int len = strlen(lf);
            if (strcmp(info, "even") == 0)
            {
                for (int i = 0; i < len; i++)
                {
                    mp[lf[i]] = 0;
                    mp[rg[i]] = 0;
                }
            }
            else if (strcmp(info, "up") == 0)
            {
                for (int i = 0; i < len; i++)
                {
                    if (mp[lf[i]] == UNKNOWN)
                        mp[lf[i]] = 1;
                    else if (mp[lf[i]] < 0)
                        mp[lf[i]] = 0;
                    else if (mp[lf[i]] > 0)
                        mp[lf[i]]++;

                    if (mp[rg[i]] == UNKNOWN)
                        mp[rg[i]] = -1;
                    else if (mp[rg[i]] > 0)
                        mp[rg[i]] = 0;
                    else if (mp[rg[i]] < 0)
                        mp[rg[i]]--;
                }
            }
            else
            {
                for (int i = 0; i < len; i++)
                {
                    if (mp[rg[i]] == UNKNOWN)
                        mp[rg[i]] = 1;
                    else if (mp[rg[i]] < 0)
                        mp[rg[i]] = 0;
                    else if (mp[rg[i]] > 0)
                        mp[rg[i]]++;

                    if (mp[lf[i]] == UNKNOWN)
                        mp[lf[i]] = -1;
                    else if (mp[lf[i]] > 0)
                        mp[lf[i]] = 0;
                    else if (mp[lf[i]] < 0)
                        mp[lf[i]]--;
                }
            }
        }

        char c = 'A';
        int maxx = 0;

        for (char ch = 'A'; ch <= 'L'; ch++)
        {
            if (mp[ch] != UNKNOWN && abs(mp[ch]) > maxx)
            {
                c = ch;
                maxx = abs(mp[ch]);
            }
        }

        printf("%c is the counterfeit coin and it is %s.\n", c, mp[c] > 0 ? "heavy" : "light");
    }

    return 0;
}
