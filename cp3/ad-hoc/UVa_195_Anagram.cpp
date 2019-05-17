#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> v;
string to_lowercase(string s) {
    string ret;
    for (int i=0; i<s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            ret += s[i] + 'a' - 'A';
        } else {
            ret += s[i];
        }
    }

    // cout << ret << endl;

    return ret;
}

bool cmp(string s1, string s2) {
    for (int i=0; i<s1.size(); i++) {
        if (s1[i] != s2[i]) {   // else skip
            // both uppercase or lowercase
            if (s1[i] >= 'A' && s1[i] <= 'Z' && s2[i] >= 'A' && s2[i] <= 'Z'
                || s1[i] >= 'a' && s1[i] <= 'z' && s2[i] >= 'a' && s2[i] <= 'z') {
                return s1[i] < s2[i];
            } else {
                char c1,c2;
                if (s1[i] >= 'A' && s1[i] <= 'Z') {
                    c1 = s1[i] + 'a' - 'A'; // to lower case
                    c2 = s2[i];
                    return c1 <= c2;
                } else {
                    c1 = s1[i];
                    c2 = s2[i] +'a'-'A';
                    return c1 < c2;
                }
            }
        }
    }
}

// Returns true if str[curr] does not match with any of the 
// characters after str[start] 
bool shouldSwap(string str, int start, int curr) 
{ 
    for (int i = start; i < curr; i++)  
        if (str[i] == str[curr]) 
            return 0; 
    return 1; 
} 
  
// Prints all distinct permutations in str[0..n-1] 
void findPermutations(string str, int index, int n) 
{ 
    if (index >= n) { 
        v.push_back(str);
        return; 
    } 
  
    for (int i = index; i < n; i++) { 
  
        // Proceed further for str[i] only if it  
        // doesn't match with any of the characters 
        // after str[index] 
        bool check = shouldSwap(str, index, i); 
        if (check) { 
            swap(str[index], str[i]); 
            findPermutations(str, index + 1, n); 
            swap(str[index], str[i]); 
        } 
    } 
} 

int main () {
    string word;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> word;
        // sort(word.begin(), word.end());
        findPermutations(word, 0, word.length());
        sort(v.begin(),v.end(),cmp);
        for (int i=0; i<v.size(); i++) {
            cout << v[i] << endl;
        }
        v.clear();
    }
}