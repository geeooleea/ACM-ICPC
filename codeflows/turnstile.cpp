#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

queue<int> entering;
queue<int> exiting;

/**
 * Solution in linear time
 */
vector<int> getTimes(vector<int> time, vector<int> direction) {
    int n = direction.size();
    vector<int> res(n);
    for (int i=0; i<n; i++) {
        if (direction[i] == 0) {
            // cout << i << " entering" << endl;
            entering.push(i);
        } else {
            // cout << i << " exiting" << endl;
            exiting.push(i);
        }
    }
    // Sentinels, queues are empty
    entering.push(n);
    exiting.push(n);

    // Fake finish time to keep min simple
    time.push_back(INT32_MAX);

    bool going_out = true;
    int t = 0; // Last time someone entered
    int ex = exiting.front(); exiting.pop();
    int ent = entering.front(); entering.pop();
    while (ex < n || ent < n) {

        while (ex < n && time[ex] <= t) { // Let everyone go out
            res[ex] = t;
            t++;
            ex = exiting.front(); exiting.pop();
        }

        while (ent < n && time[ent] <= t) { // Let everyone go in
            if (time[ent] > t) break;
            res[ent] = t;
            t++;
            ent = entering.front(); entering.pop();
        }

        t = max(t,min(time[ent], time[ex]));
    }
    
    for (int i=0; i<n; i++) {
        cout << res[i] << endl;
    } 
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string time_count_temp;
    getline(cin, time_count_temp);

    int time_count = stoi(ltrim(rtrim(time_count_temp)));

    vector<int> time(time_count);

    for (int i = 0; i < time_count; i++) {
        string time_item_temp;
        getline(cin, time_item_temp);

        int time_item = stoi(ltrim(rtrim(time_item_temp)));

        time[i] = time_item;
    }

    string direction_count_temp;
    getline(cin, direction_count_temp);

    int direction_count = stoi(ltrim(rtrim(direction_count_temp)));

    vector<int> direction(direction_count);

    for (int i = 0; i < direction_count; i++) {
        string direction_item_temp;
        getline(cin, direction_item_temp);

        int direction_item = stoi(ltrim(rtrim(direction_item_temp)));

        direction[i] = direction_item;
    }

    vector<int> result = getTimes(time, direction);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
