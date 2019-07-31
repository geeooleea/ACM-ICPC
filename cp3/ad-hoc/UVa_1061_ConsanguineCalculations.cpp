#include <bits/stdc++.h>

using namespace std;

enum BLOOD_T { O, A, B };
enum RH_T { NEG, POS };

enum BLOOD_T_2 { O_NEG, O_POS, AB_NEG, AB_POS, B_NEG, B_POS, A_NEG, A_POS};

string types[8] = { "O-", "O+", "AB-", "AB+", "B-", "B+", "A-", "A+" };

struct bloodType {
    vector<BLOOD_T> t;
    RH_T rh;
};

bloodType getBT(string s) {
    bloodType b;
    switch (s[0]) {
        case 'A': b.t.push_back(A); break;
        case 'B': b.t.push_back(B); break;
        case 'O': b.t.push_back(O); break;
    }

    if (s.length() == 3) {
        switch (s[1]) {
            case 'A': b.t.push_back(A); break;
            case 'B': b.t.push_back(B); break;
            case 'O': b.t.push_back(O); break;
        }
        if (s[2] == '+') b.rh = POS; else b.rh = NEG;
    } else {
        b.t.push_back(O);
        if (s[1] == '+') b.rh = POS; else b.rh = NEG;
    }
    return b;
}

vector<BLOOD_T_2> findChild(string p1, string p2) {
    bloodType p1b = getBT(p1);
    bloodType p2b = getBT(p2);
    //cout << "Created bt" << endl;
    vector<BLOOD_T_2> res;
    for (BLOOD_T t1 : p1b.t) {
        for (BLOOD_T t2 : p2b.t) {
            if (t1 + t2 == 0) { // (O,O)
                if (p1b.rh + p2b.rh >= 1) { // RH (+,-) or (+,+), both possible in child
                    res.push_back(O_POS); res.push_back(O_NEG);
                } else if (p1b.rh + p2b.rh == 0) { // RH (-,-)
                    res.push_back(O_NEG);
                }
            } else if (t1 + t2 == 1 || t1 == A && t2 == A) { // (A,O) or (A,A)
                if (p1b.rh + p2b.rh >= 1) { // RH (+,-) or (+,+), both possible in child
                    res.push_back(A_POS); res.push_back(A_NEG);
                } else if (p1b.rh + p2b.rh == 0) { // RH (-,-)
                    res.push_back(A_NEG);
                }
            } else if (t1 + t2 == 3) { // (A,B)
                if (p1b.rh + p2b.rh >= 1) { // RH (+,-) or (+,+), both possible in child
                    res.push_back(AB_POS); res.push_back(AB_NEG);
                } else if (p1b.rh + p2b.rh == 0) { // RH (-,-)
                    res.push_back(AB_NEG);
                }
            } else if (t1 + t2 == 4 || t1 + t2 == 2) { // (B,B) or (B,O) [CASE (A,A) = 2 already handled]
                if (p1b.rh + p2b.rh >= 1) { // RH (+,-) or (+,+), both possible in child
                    res.push_back(B_POS); res.push_back(B_NEG);
                } else if (p1b.rh + p2b.rh == 0) { // RH (-,-)
                    res.push_back(B_NEG);
                }
            }
        }
    }
    sort( res.begin(), res.end() );
    res.erase( unique( res.begin(), res.end() ), res.end() );
    return res;
}

vector<BLOOD_T_2> findParent(string p1, string c) {
    bloodType child = getBT(c);
    BLOOD_T_2 btc;
    switch (child.t[0]) {
        case O: if (child.rh == POS) btc = O_POS; else btc = O_NEG; break;
        case A:
            if (child.t[1] == O) if (child.rh == POS) btc = A_POS; else btc = A_NEG; 
            else if (child.rh == POS) btc = AB_POS; else btc = AB_NEG; break;
        case B: if (child.rh == POS) btc = B_POS; else btc = B_NEG; break;
    }
    
    vector<BLOOD_T_2> res;
    for (int i=0; i<8; i++) {
        vector<BLOOD_T_2> v = findChild(p1,types[i]);
        // cout << p1 << " + " << types[i] << " = "; for (BLOOD_T_2 s : v) cout << s << ", "; cout << endl;
        for (BLOOD_T_2 s : v) if (s == btc) res.push_back((BLOOD_T_2)i);
    }

    sort( res.begin(), res.end() );
    res.erase( unique( res.begin(), res.end() ), res.end() );

    return res;    
}

int main() {
    string p1,p2,c;

    int t = 0;

    while (cin >> p1 >> p2 >> c) {
        if (p1[0] == 'E') break;
        // cout << p1 << " " << p2 << " " << c << endl;
        if (p2[0] == '?') {
            vector<BLOOD_T_2> parent = findParent(p1,c);
            cout << "Case " << ++t << ": " << p1 << " ";
            if (parent.size() > 1) {
                cout << "{"; 
                for (int i=0; i<parent.size(); i++) {
                    cout << types[parent[i]];
                    if (i < parent.size()-1) cout << ", ";
                }
                cout << "}";
            } else if (parent.size() == 1 ) cout << types[parent[0]];
            else cout << "IMPOSSIBLE";
            cout << " " << c << endl;
        } else if (c[0] == '?') {
            vector<BLOOD_T_2> child = findChild(p1,p2);
            cout << "Case " << ++t << ": " << p1 << " " << p2 << " ";
            if (child.size() > 1) {
                cout << "{"; 
                for (int i=0; i<child.size(); i++) {
                    cout << types[child[i]];
                    if (i < child.size()-1) cout << ", ";
                }
                cout << "}";
            } else if (child.size() == 1 ) cout << types[child[0]];
            else cout << "IMPOSSIBLE";
            cout << endl;
        } else {
            vector<BLOOD_T_2> parent = findParent(p2,c);
            cout << "Case " << ++t << ": ";
            if (parent.size() > 1) {
                cout << "{"; 
                for (int i=0; i<parent.size(); i++) {
                    cout << types[parent[i]];
                    if (i < parent.size()-1) cout << ", ";
                }
                cout << "}";
            } else if (parent.size() == 1 ) cout << types[parent[0]];
            else cout << "IMPOSSIBLE";
            cout << " " << p2 << " " << c << endl;
        }
    }
    return 0;
}