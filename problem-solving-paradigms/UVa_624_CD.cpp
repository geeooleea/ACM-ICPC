#include <iostream>
#include <vector>

using namespace std;

int best_time=0;

int N,M;
int tracks[20];
vector<bool> used_arr(20,false);
vector<bool> used(20, false);

void fill_CD(int time_used,int curr, int last_track,vector<bool> used) {
    // Either i have finished time or i have finished the tracks
    if (time_used >= N || curr == M) {
        if (time_used <= N && time_used > best_time) {
            best_time = time_used;
            for(int i=0; i<M; i++) {
                used_arr[i] = used[i];
            }
        } else if (time_used > N && N - (time_used - tracks[last_track]) > best_time ) {
            best_time = (time_used - tracks[last_track]);
            used[last_track] = false;
            for(int i=0; i<M; i++) {
                used_arr[i] = used[i];
            }
        }
    } else {
        used[curr] = true;
        fill_CD(time_used+tracks[curr],curr+1,curr,used);
        used[curr] = false;
        fill_CD(time_used,curr+1,last_track,used);
    }
}

int main() {
    while (cin >> N >> M) {
        for (int i=0; i<M; i++) {
            cin >> tracks[i];
        }
        /*
        for (int i=0; i<M; i++) {
            used[i] = true;
            fill_CD(tracks[i],i+1,i,used);
            used.resize(20,false);
        }
        */
        fill_CD(0,0,-1,used);

        for (int i=0; i < M; i++) {
            if (used_arr[i]) {
                cout << tracks[i] << " ";
            }
        }

        cout << "sum:" << best_time << endl;
        used.resize(20,false);
        used_arr.resize(20,false);
        best_time = 0;
    }
}