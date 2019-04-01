#include <cstdio>
#include <cmath>

#define EPS 0.000001

using namespace std;

int main()
{
    double c;

    scanf("%lf", &c);

    while (fabs(c) > EPS)
    {
        int n = 1;
        double sum = (double) 1 / (n + 1);

        while (sum < c)
        {
            n++;
            sum += (double) 1 / (n + 1);
        }
        printf("%d card(s)\n", n);
        scanf("%lf", &c);
    }

    return 0;
}
