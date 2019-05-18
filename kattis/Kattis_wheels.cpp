#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

long long x[1001];
long long y[1001];
long long r[1001];

// raggio del padre della ruota i
// se p_num[i] == -1 non abbiamo ancora considerato i
long long p_num[1001];
long long p_den[1001];

// se false scrivo counterclockwise
bool clockwise[1001];

long long sq_dist(int a, int b) {
	return pow(x[a]-x[b],2) + pow(y[a]-y[b],2);
}

int main() {
	int t;
	cin >> t;
	int n;
	for (int test = 0; test < t; test++) {
	 	cin >> n;
		for (int i=0; i<n; i++) {
		    p_num[i] = -1;
		    p_den[i] = 1;
		    clockwise[i] = false;
		}
		for (int i=0; i<n; i++) {
		    cin >> x[i] >> y[i] >> r[i];
		}

		cout << "1 clockwise" << endl;
		clockwise[0] = true;
		p_num[0] = 1;
		p_den[0] = 1;

		int mcd;
		queue<int> s;
		s.push(0);
		while (!s.empty()) {
		    int current = s.front();
		    s.pop();
		    for (int i=1; i<n; i++) {
			if (i != current && p_num[i] == -1 
			        && sq_dist(current,i) == pow((r[current] + r[i]),2) ) {
			    s.push(i);
			    // p_r[i] = r[current];
			    p_num[i] = p_num[current] * r[current];
			    p_den[i] = p_den[current] * r[i]; 
			    mcd = __gcd(p_num[i],p_den[i]);
			    p_num[i] /= mcd;
			    p_den[i] /= mcd;
			    clockwise[i] = !clockwise[current];
			}
		    }
		}

		for (int i=1; i<n; i++) {
		    if (p_num[i] == -1 || p_num[i] == 0) {
			cout << "not moving" << endl;
		    } else {
			if (p_den[i] == 1) {
			    cout << p_num[i] << " " << (clockwise[i] ? "clockwise" : "counterclockwise") << endl;
			} else {
			    cout << p_num[i] << "/" << p_den[i] << " " << (clockwise[i] ? "clockwise" : "counterclockwise") << endl;
			}
		    }
		}
	}
    return 0;
}
