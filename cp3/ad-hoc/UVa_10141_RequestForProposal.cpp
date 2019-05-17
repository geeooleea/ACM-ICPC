#include <iostream>
#include <vector>

using namespace std;

int n,p,r;

vector<double> costs;
vector<string> proposal;
vector<int> requirements_met;

int main() {
    int test_case = 1;
    while (cin >> n >> p) {
        if (n==0 && p==0) {
            break;
        }
        // read and discard \n ?
        getchar();
        costs.resize(p);
        proposal.resize(p);
        requirements_met.resize(p);
        string tmp;
        for (int i=0; i<n; i++) {
            getline(cin, tmp);
        }

        int k;
        for (int i=0; i<p; i++) {
            getline(cin,proposal[i]);
            cin >> costs[i] >> requirements_met[i];
            getchar();
            for (int j=0; j<requirements_met[i]; j++) {
                getline(cin, tmp);
            }
        }
        int best_index = 0;
        for (int i=1; i<p; i++) {
            if (requirements_met[i] > requirements_met[best_index]) {
                best_index = i;
            } else if (requirements_met[i] == requirements_met[best_index] &&
                        costs[i] < costs[best_index]) {
                best_index = i;
            }
        }

        cout << (test_case == 1 ? "" : "\n") << "RFP #" << test_case << endl << proposal[best_index] << endl;
        test_case++;
    }
}