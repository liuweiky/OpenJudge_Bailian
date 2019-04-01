#include <cstdio>

using namespace std;

int main()
{
    double sum = 0;
    for (int i = 0; i < 12; i++)
    {
        double t;
        scanf("%lf", &t);
        sum += t;
    }
    printf("$%.2f", sum / 12);
    return 0;
}
