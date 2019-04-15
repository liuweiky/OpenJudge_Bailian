#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

#define MAX_NUMBER 31269

using namespace std;

int T;

long long len_end_with_i[MAX_NUMBER];

int main()
{
    ios::sync_with_stdio(false);
    /**max_i = 31268*/
    long long total_len = 0;
    long long prev_len = 0;
    stringstream ss;
    for (long long i = 1; ; i++)
    {
        ss.str("");
        ss.clear();
        ss << i;
        string s;
        ss >> s;
        //cout << s << endl;
        long long len = prev_len + s.size();
        total_len += len;
        len_end_with_i[i] = total_len;
        if (total_len > 2147483647LL)
        {
            //cout << i << endl;
            break;
        }
        prev_len = len;
    }

    cin >> T;

    while (T--)
    {
        int idx;
        cin >> idx;

        int low = 1, high = MAX_NUMBER - 1;

        int before_idx_min_num;
        bool flag = false;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if (idx > len_end_with_i[mid])
            {
                low = mid + 1;
                before_idx_min_num = mid;
            }
            else if (idx < len_end_with_i[mid])
                high = mid - 1;
            else
            {
                flag = true;
                cout << mid % 10 << endl;
                break;
            }
        }

        if (flag)
            continue;

        string numstr = "";
        //cout << '\t' << before_idx_min_num  << '\t' << len_end_with_i[before_idx_min_num] << endl;
        int sz = idx - len_end_with_i[before_idx_min_num];

        for (int num = 1; ; num++)
        {
            ss.str("");
            ss.clear();
            ss << num;
            string s;
            ss >> s;
            numstr += s;
            if (numstr.size() >= sz)
            {
                cout << numstr[sz - 1] << endl;
                break;
            }
        }
    }


    return 0;
}
