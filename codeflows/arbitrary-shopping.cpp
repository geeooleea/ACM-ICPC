#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/**
 * Find the longest sub-array of outfits with sum <= money
 */
int getMaximumOutfits(vector<int> outfits, int money) {
    int maxlen = 0, currlen = 0;
    int n = outfits.size();
    int sum = 0;
    for (int i=0; i<n; i++) {
        if (sum + outfits[i] <= money) {
            sum += outfits[i];
            currlen++;
        } else if (sum > 0) {
            sum = sum - outfits[i-currlen] + outfits[i];
        }
        
        maxlen = max(maxlen,currlen);
    }
    // cout << maxlen<< endl;
    return maxlen;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string outfits_count_temp;
    getline(cin, outfits_count_temp);

    int outfits_count = stoi(ltrim(rtrim(outfits_count_temp)));

    vector<int> outfits(outfits_count);

    for (int i = 0; i < outfits_count; i++) {
        string outfits_item_temp;
        getline(cin, outfits_item_temp);

        int outfits_item = stoi(ltrim(rtrim(outfits_item_temp)));

        outfits[i] = outfits_item;
    }

    string money_temp;
    getline(cin, money_temp);

    int money = stoi(ltrim(rtrim(money_temp)));

    int result = getMaximumOutfits(outfits, money);

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
