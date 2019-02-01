#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

long long f_three[1000001];
long long f_four[1000001];

void computef() {
    f_three[1] = f_four[1] = 1;
    f_three[2] = f_four[2] = 2;
    f_three[3] = f_four[3] = 4;
    f_three[4] = 7;
    f_four[4] = 8;

    for (int i=5; i<1000001; i++) {
        f_three[i] = f_three[i-1] + f_three[i-2] + f_three[i-3];
        f_three[i] = f_three[i] % 1000000007;
        f_four[i] = f_four[i-1] + f_four[i-2] + f_four[i-3] + f_four[i-4];
        f_four[i] = f_four[i] % 1000000007;
    }
}

/*
 * Complete the 'countMessages' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY keys
 *  2. STRING message
 */
int coded[40000001];
int countMessages(vector<string> keys, string message) {
    computef();
    int pos[27];
    int num[27];
    for (int i=0; i<8; i++) {
        for (int j=0; j<keys[i].length(); j++) {
            num[keys[i][j]-'A'] = i+2;
            pos[keys[i][j]-'A'] = j+1;
        }
    }

    int len = 0;
    for (int i=0; i<message.length(); i++) {
        if (message[i] != ' ') {
            int c = message[i] - 'A';
            for (int i=0; i<pos[c]; i++) {
                coded[len++] = num[c];
            }
        } else {
            coded[len++] = 0;
        }
    }
    long long res = 1;

    for (int i=0; i<len;) {
        int j=i;
        while (coded[j] == coded[i]) {
            j++;
        }
        // cout << i << " " << j << " ";
        if (coded[i] != 1) {
            if (keys[coded[i]-2].length() == 3) {
                // cout << f_three[j-i] << endl;
                res*=f_three[j-i];
            } else {
                // cout << f_four[j-i] << endl;
                res*=f_four[j-i];
            }
            res = res % 1000000007;
        }
        i=j;
    }
    cout << res << endl;
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string keys_count_temp;
    getline(cin, keys_count_temp);

    int keys_count = stoi(ltrim(rtrim(keys_count_temp)));

    vector<string> keys(keys_count);

    for (int i = 0; i < keys_count; i++) {
        string keys_item;
        getline(cin, keys_item);

        keys[i] = keys_item;
    }

    string message;
    getline(cin, message);

    int result = countMessages(keys, message);

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
