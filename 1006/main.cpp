#include <cstdio>
#include <algorithm>

using namespace std;

int p, e, i, d;

int main()
{
    scanf("%d %d %d %d", &p, &e, &i, &d);

    int cnt = 1;

    while (p != -1 && e != -1 && i != -1 && d != -1)
    {
        int day = d + 1;
        while (true)
        {
            if (abs(day - p) % 23 == 0 && abs(day - e) % 28 == 0 && abs(day - i) % 33 == 0)
            {
                printf("Case %d: the next triple peak occurs in %d days.\n", cnt++, day - d);
                break;
            }
            day++;
        }

        scanf("%d %d %d %d", &p, &e, &i, &d);
    }

    return 0;
}
