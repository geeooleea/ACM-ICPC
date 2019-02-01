#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/**
 * Solution in linear time
 */
int exam(vector<int> v) {
    int yourres = 0, hisres = 0;
    vector<int> tmp(v.size());
    tmp[0] = (v[0] == 0 ? -1 : 1 );
    for (int i=1; i<v.size(); i++) {
        if (v[i] == 1) {
            tmp[i] = tmp[i-1] +1;
        } else {
            tmp[i] = tmp[i-1] -1;
        }
    }
    for (int i=0; i<tmp.size(); i++) {
        hisres = tmp[tmp.size()-1] - yourres;
        if (yourres > hisres) {
            return i;
        }
        yourres = tmp[i];
    }
    return (tmp[tmp.size()-1] > 0 ? 0 : tmp.size()-1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string v_count_temp;
    getline(cin, v_count_temp);

    int v_count = stoi(ltrim(rtrim(v_count_temp)));

    vector<int> v(v_count);

    for (int i = 0; i < v_count; i++) {
        string v_item_temp;
        getline(cin, v_item_temp);

        int v_item = stoi(ltrim(rtrim(v_item_temp)));

        v[i] = v_item;
    }

    int result = exam(v);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
