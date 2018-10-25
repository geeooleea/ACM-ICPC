#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> subject;

int main () {
    int n,s,tmp;
    cin >> n >> s;
    long long swaps = 0;
    long long counter = 0;
    for (int i=0; i<n; i++) {
        cin >> tmp;
        if (subject.count(tmp)) {
            swaps += subject[tmp];
        }
        else {
            swaps += counter;
            subject.emplace(tmp,counter);
            counter++;
        }
    }

    cout << swaps << endl;


    return 0;
}