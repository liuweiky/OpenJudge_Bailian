#include <iostream>
#include <string>
#include <sstream>

#define MAX_LEN 2048

using namespace std;

struct bign
{
    int digit[MAX_LEN];
    int len;
    bign() {len = 0;}
};

string sdouble;
int n, llen = 0, rlen = 0, dot_pos = 0;

bign mul(bign bg, int k)
{
    bign res;
    int carry = 0;

    for (int i = 0; i < bg.len; i++)
    {
        int t =  bg.digit[i] * k + carry;
        res.digit[res.len++] = t % 10;
        carry = t / 10;
    }

    while (carry != 0)
    {
        res.digit[res.len++] = carry % 10;
        carry /= 10;
    }

    return res;
}

void cal()
{
    bign num;

    dot_pos = sdouble.find(".");
    llen = dot_pos;
    rlen = sdouble.size() - 1 - llen;

    string temp_double = sdouble;
    temp_double.erase(temp_double.begin() + dot_pos);

    for (int i = temp_double.size() - 1; i >= 0; i--)
        num.digit[num.len++] = temp_double[i] - '0';


    stringstream ss;
    ss << temp_double;
    int k;
    ss >> k;

    for (int i = 0; i < n - 1; i++)
        num = mul(num, k);

    while (num.len < n * rlen)
        num.digit[num.len++] = 0;

    int dot_ptr = n * rlen - 1;

    int end_ptr = 0;

    while (num.digit[end_ptr] == 0 && end_ptr <= dot_ptr)
        end_ptr++;

    for (int i = num.len - 1; i >= 0 && i >= end_ptr; i--)
    {
        if (i == dot_ptr)
            cout << '.';
        cout << num.digit[i];
    }
    cout << endl;

}

int main()
{
    while (cin >> sdouble >> n)
        cal();
    return 0;
}
