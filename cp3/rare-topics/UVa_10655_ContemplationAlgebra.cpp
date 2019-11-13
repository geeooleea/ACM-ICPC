#include <bits/stdc++.h>
#define N 2

using namespace std;

struct Matrix { int mat[N][N]; }; // Return matrix by value

Matrix matrixMul(Matrix a, Matrix b) {
    Matrix res;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k = res.mat[i][j] = 0; k < N; k++)
                res.mat[i][j] += a.mat[i][k] * b.mat[k][j];
        }
    }
    return res;
}

Matrix matrixPow(Matrix a, int p) {
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
    long long p,q,n;

    while (cin >> p >> q) {
        if (p == 0 && q == 0) break;
        cin >> n;
        Matrix a;
        a.mat[0][0] = p;
        a.mat[0][1] = -q;
        a.mat[1][0] = 1;
        a.mat[1][1] = 0;

        Matrix an = matrixPow(a,n);
        cout << an.mat[1][0] * p << endl;
        return 0;
    }
}