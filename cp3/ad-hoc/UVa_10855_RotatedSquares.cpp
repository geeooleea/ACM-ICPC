using namespace std;

#include <iostream>


int N,n;

char **big;
char **small;

int match() {
    bool matches;
    int counter = 0;
    for (int i=0; i<N-n+1; i++) {
        for (int j=0; j<N-n+1; j++) {
            matches = true;
            for (int k=0; k<n && matches; k++) {
                for (int l=0; l<n && matches; l++) {
                    if(small[k][l] != big[i+k][j+l]) {
                        matches = false;
                    }
                }
            }
            if (matches) {
                counter++;
            }
        }
    }
    return counter;
}

void rotate() {
    char **tmp = new char*[n];
    for (int i=0; i<n; i++) {
        tmp[i] = new char[n];
        for (int j=0; j<n; j++) {
            tmp[i][j] = small[n-j-1][i];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            small[i][j] = tmp[i][j];
        }
    }
}

int main() {
    while (cin >> N >> n) {
        if (N == 0 && n == 0) {
            break;
        }
        big = new char*[N];
        small = new char*[n];

        for (int i=0; i<N; i++) {
            big[i] = new char[N];
            for (int j=0; j<N; j++) {
                cin >> big[i][j];
            }
        }

        for (int i=0; i<n; i++) {
            small[i] = new char[n];
            for (int j=0; j<n; j++) {
                cin >> small[i][j];
            }
        }

        // ROTATION 0
        cout << match() << " ";
        
        // ROTATION 90
        rotate();
        
        cout << match() << " ";

        // ROTATION 180
        rotate();

        cout << match() << " ";

        // ROTATION 270
        rotate();

        cout << match() << endl;

        for (int i=0; i<N; i++) {
            delete [] big[i];
        }

        for (int i=0; i<n; i++) {
            delete [] small[i];
        }

        delete [] big; delete [] small;
    }
    
    return 0;
}