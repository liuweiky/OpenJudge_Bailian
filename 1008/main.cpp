#include <cstdio>
#include <map>
#include <string>

using namespace std;

map<string, int> haab_month;
string tzolkin_month_name[] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int N;

int main()
{
    haab_month["pop"] = 0; haab_month["no"] = 1; haab_month["zip"] = 2; haab_month["zotz"] = 3;
    haab_month["tzec"] = 4; haab_month["xul"] = 5; haab_month["yoxkin"] = 6; haab_month["mol"] = 7;
    haab_month["chen"] = 8; haab_month["yax"] = 9; haab_month["zac"] = 10; haab_month["ceh"] = 11;
    haab_month["mac"] = 12; haab_month["kankin"] = 13; haab_month["muan"] = 14; haab_month["pax"] = 15;
    haab_month["koyab"] = 16; haab_month["cumhu"] = 17; haab_month["uayet"] = 18;

    scanf("%d", &N);
    printf("%d\n", N);
    while (N--)
    {
        char buf[32];
        int n, m, y;
        scanf("%d. %s %d", &n, buf, &y);
        m = haab_month[buf];
        int day = y * 365 + m * 20 + n;
        int number = day % 13 + 1;
        int nname = day % 20;
        int year = day / 260;
        printf("%d %s %d\n", number, tzolkin_month_name[nname].c_str(), year);
    }

    return 0;
}
