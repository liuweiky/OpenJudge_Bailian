#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int cnt1, cnt2, cnt3, cnt4, cnt5, cnt6;

    while (true)
    {
        scanf("%d %d %d %d %d %d", &cnt1, &cnt2, &cnt3, &cnt4, &cnt5, &cnt6);
        if (cnt1 == 0 && cnt2 == 0 && cnt3 == 0 && cnt4 == 0 && cnt5 == 0 && cnt6 == 0)
            return 0;
        int block3_need = (int)ceil((double) cnt3 / 4);
        int ans = cnt6 + cnt5 + cnt4 + block3_need;
        int cnt5_remain = cnt5 * 11;
        int cnt4_remain = cnt4 * 20;
        int cnt3_remain = block3_need * 36 - cnt3 * 9;

        if (cnt3_remain / 9 == 1)
        {
            if (cnt2 <= 1)
            {
                cnt5_remain += (cnt3_remain - 4 * cnt2);
                cnt2 = 0;
            }
            else
            {
                cnt2 -= 1;
                cnt5_remain += 5;
            }
        }
        else if (cnt3_remain / 9 == 2)
        {
            if (cnt2 <= 3)
            {
                cnt5_remain += (cnt3_remain - 4 * cnt2);
                cnt2 = 0;
            }
            else
            {
                cnt2 -= 3;
                cnt5_remain += 6;
            }
        }
        else if (cnt3_remain / 9 == 3)
        {
            if (cnt2 <= 5)
            {
                cnt5_remain += (cnt3_remain - 4 * cnt2);
                cnt2 = 0;
            }
            else
            {
                cnt2 -= 5;
                cnt5_remain += 7;
            }
        }

        if (cnt2 <= cnt4_remain / 4)
        {
            cnt5_remain += (cnt4_remain - 4 * cnt2);
            cnt2 = 0;
        }
        else
        {
            cnt2 -= cnt4_remain / 4;
        }

        ans += (int)ceil((double)cnt2 / 9);
        int cnt2_remain = (int)ceil((double)cnt2 / 9) * 36 - cnt2 * 4;
        cnt5_remain += cnt2_remain;
        if (cnt1 <= cnt5_remain)
            printf("%d\n", ans);
        else
            printf("%d\n", ans + (int)ceil((double)(cnt1 - cnt5_remain) / 36));
    }

    return 0;
}
