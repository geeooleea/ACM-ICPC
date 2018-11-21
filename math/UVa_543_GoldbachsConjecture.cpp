#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

bool prime[1000001] = {true};
bool isPrime(int n){ 
    bool p=true; 
    for(int i=2;i < (int)ceil(sqrt(n));i++) 
        if(n%i==0)p=false;
    return p; 
} 

void SieveOfEratosthenes(int n) 
{   
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p 
            for (int i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    }
} 

int main() {
    int n;
    bool found;
    SieveOfEratosthenes(1000000); 
    while (cin >> n) {
        if (n==0) break;
        found = false;
        for (int i=2; i<n/2+1 && !found; i++) {
            if (prime[i] && prime[n-i]) {
                cout << n << " = " << i << " + " << n-i << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
    
    return 0;
}