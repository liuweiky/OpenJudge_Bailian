#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

map<string, int> tels;
map<char, char> rep;

int N;

void add_tel(string tel)
{
    //cout << tel << endl;
    int pos = tel.find("-");
    while (pos != string::npos)
    {
        tel.erase(tel.begin() + pos);
        pos = tel.find("-");
    }

    for (int i = 0; i < tel.size(); i++)
    {
        if (isalpha(tel[i]) && tel[i] != 'Q' && tel[i] != 'Z')
            tel[i] = rep[tel[i]];
    }
    //cout << tel << endl;
    if (tels.find(tel) == tels.end())
        tels[tel] = 1;
    else
        tels[tel]++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    rep['A'] = '2'; rep['B'] = '2'; rep['C'] = '2';
    rep['D'] = '3'; rep['E'] = '3'; rep['F'] = '3';
    rep['G'] = '4'; rep['H'] = '4'; rep['I'] = '4';
    rep['J'] = '5'; rep['K'] = '5'; rep['L'] = '5';
    rep['M'] = '6'; rep['N'] = '6'; rep['O'] = '6';
    rep['P'] = '7'; rep['R'] = '7'; rep['S'] = '7';
    rep['T'] = '8'; rep['U'] = '8'; rep['V'] = '8';
    rep['W'] = '9'; rep['X'] = '9'; rep['Y'] = '9';

    cin >> N;

    while (N--)
    {
        string s;
        cin >> s;
        add_tel(s);
    }

    bool flag = true;

    for (map<string, int>::iterator it = tels.begin(); it != tels.end(); it++)
    {
        if (it->second >= 2)
        {
            flag = false;
            string str = it->first;
            for (int i = 0; i < str.size(); i++)
            {
                if (i == 3)
                    cout << '-';
                cout << str[i];
            }
            cout << ' ' << it->second << endl;
        }
    }

    if (flag)
        cout << "No duplicates.";

    return 0;
}
