#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int findBreakDuration(int n, int k, int t, vector<int> start, vector<int> finish) {
    vector<int> breaks(n+2);
    breaks[0] = start[0];
    for (int i=1; i<n; i++) {
        breaks[i] = start[i] - finish[i-1];
    }
    breaks[n] = t - finish[n-1];
    // Sottovettore di k+1 elementi consecutivi di somma massima
    int maxbreak = 0;
    int currbreak = 0;
    for (int i=0; i<k+1; i++) {
        currbreak += breaks[i];
    }
    maxbreak = currbreak;
    for (int i=k+1; i<=n; i++) {
        currbreak = currbreak - breaks[i-k-1] + breaks[i];
        maxbreak = max(maxbreak,currbreak);
    }
    cout << maxbreak << endl;
    return maxbreak;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    string start_count_temp;
    getline(cin, start_count_temp);

    int start_count = stoi(ltrim(rtrim(start_count_temp)));

    vector<int> start(start_count);

    for (int i = 0; i < start_count; i++) {
        string start_item_temp;
        getline(cin, start_item_temp);

        int start_item = stoi(ltrim(rtrim(start_item_temp)));

        start[i] = start_item;
    }

    string finish_count_temp;
    getline(cin, finish_count_temp);

    int finish_count = stoi(ltrim(rtrim(finish_count_temp)));

    vector<int> finish(finish_count);

    for (int i = 0; i < finish_count; i++) {
        string finish_item_temp;
        getline(cin, finish_item_temp);

        int finish_item = stoi(ltrim(rtrim(finish_item_temp)));

        finish[i] = finish_item;
    }

    int result = findBreakDuration(n, k, t, start, finish);

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
