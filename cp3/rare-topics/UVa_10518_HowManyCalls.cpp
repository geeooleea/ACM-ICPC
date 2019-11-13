#include <bits/stdc++.h>
#define N 2

long long n,base;

using namespace std;

struct Matrix { long long mat[N][N]; }; // Return matrix by value

Matrix matrixMul(Matrix a, Matrix b) {
    Matrix res;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k = res.mat[i][j] = 0; k < N; k++)
                res.mat[i][j] += (a.mat[i][k] % base * b.mat[k][j] % base) % base;
                res.mat[i][j] %= base;
        }
    }
    return res;
}

Matrix matrixPow(Matrix a, long long p) {
    Matrix res;
    for (int i=0; i<N; i++) // Initialize res to identity matrix
        for (int j=0; j<N; j++) 
            res.mat[i][j] = (i==j);

    while (p > 0) {
        if (p & 1) res = matrixMul(res,a);
        a = matrixMul(a,a);
        p >>= 1;
    }
    return res;
}

int main() {
    int t = 1;
    while (cin >> n >> base) {
        if (n==0 && base==0) break;
        Matrix a;
        a.mat[0][0] = a.mat[0][1] = a.mat[1][0] = 1;
        a.mat[1][1] = 0;
        cout << "Case " << t++ << ": " << n << " " << base << " "; 
        if (n==0) cout << 1%base << endl;
        else
            cout << (((2 * matrixPow(a,n+1).mat[0][1] % base - 1 + base) % base) % base) << endl;
    }

    return 0;
}