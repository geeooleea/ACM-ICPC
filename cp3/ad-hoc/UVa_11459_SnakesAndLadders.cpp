#include <bits/stdc++.h>

using namespace std;

int main() {
    int test, players, warps, die;
    cin >> test;
    for (int t=0; t<test; t++) {
        cin >> players >> warps >> die;
        vector<int> warp(101,-1); int w;
        for (int i=0; i<warps; i++) {
            cin >> w;
            cin >> warp[w];
        }
        int roll;
        int p=1;
        vector<int> pos(players+1,1);
        // cerr << "Players " << players << endl;
        
        for (int i=0; i<die; i++) {
            cin >> roll;
            pos[p] = min(pos[p]+roll, 100);
            if (warp[pos[p]] > 0) pos[p] = min(warp[pos[p]],100);
            if (pos[p] == 100) while (++i<die) cin >> roll;
            p = (p)%players + 1;
            // cerr << p << endl;
        }

        for (int i=1; i<=players; i++) {
            cout << "Position of player " << i << " is " << pos[i] << "." << endl;
        }
    }
    return 0;
}