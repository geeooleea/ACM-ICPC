#include <bits/stdc++.h>
#define N 2

int n,m;

using namespace std;

struct Matrix { long long mat[N][N]; }; // Return matrix by value

Matrix matrixMul(Matrix a, Matrix b) {
    Matrix res;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k = res.mat[i][j] = 0; k < N; k++)
                res.mat[i][j] += (a.mat[i][k] % m * b.mat[k][j] % m) % m;
                res.mat[i][j] %= m;
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

    while (cin >> n >> m) {
        m = pow(2,m);
        Matrix a;
        a.mat[0][0] = a.mat[0][1] = a.mat[1][0] = 1;
        a.mat[1][1] = 0;

        cout << matrixPow(a,n).mat[0][1] << endl;
    }

    return 0;
}