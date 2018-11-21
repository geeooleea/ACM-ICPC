// TLE Solution
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool prime[10000001];

void SieveOfEratosthenes(ll n) {
    memset(prime,1,sizeof(prime));
    for (int p=2; p*p<=n; p++) { 
        if (prime[p] == true) {
            for (int i=p*2; i<=n; i += p) {
                prime[i] = false; 
            }
        } 
    }
}

int main() {
    long long n,customers;
    SieveOfEratosthenes(10000001);
    cin >> n;
    while (n != 1) {
        customers = 0;
        ll lim = sqrt(n)+1;
        for (int i=2; i < lim; i++) {
            if (prime[i]) {
                while (n%i == 0) {
                    customers++;
                    n/=i;
                }
            }
        }
        if (n>1) customers++;
        cout << customers << endl;
        cin >> n;
    }
   return 0;
}