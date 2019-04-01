#include <cstdio>
#include <cmath>

#define PI 3.14159265

using namespace std;

int N;

int main()
{
    scanf("%d", &N);

    int cnt = 1;

    while (N--)
    {
        double x, y;
        scanf("%lf %lf", &x, &y);
        double r2 = x * x + y * y;
        double s = r2 * PI / 2;
        printf("Property %d: This property will begin eroding in year %d.\n", cnt++, (int) (s / 50) + 1);
    }
    printf("END OF OUTPUT.");
    return 0;
}
