#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define MAX_N 64

using namespace std;

struct pkg
{
    int cnt;
    char str[MAX_N];
    int prev_cnt[128];
    pkg() {fill_n(prev_cnt, 128, 0); cnt = 0;}
};

vector<pkg> pkgs;
int N, M;

bool cmp(pkg& p1, pkg& p2)
{
    if (p1.cnt != p2.cnt)
        return p1.cnt < p2.cnt;
    return strcmp(p1.str, p2.str) < 0;
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        char ch = getchar();
        pkg p;
        for (int j = 0; j < N; j++)
        {
            ch = getchar();
            p.str[j] = ch;
            if (ch == 'A')
                p.cnt += p.prev_cnt['C'] + p.prev_cnt['G'] + p.prev_cnt['T'];
            else if (ch == 'C')
                p.cnt += p.prev_cnt['G'] + p.prev_cnt['T'];
            else if (ch == 'G')
                p.cnt += p.prev_cnt['T'];
            p.prev_cnt[ch]++;
        }
        p.str[N] = '\0';
        pkgs.push_back(p);
    }

    sort(pkgs.begin(), pkgs.end(), cmp);

    for (int i = 0; i < M; i++)
        printf("%s\n", pkgs[i].str);

    return 0;
}
