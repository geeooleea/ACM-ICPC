using namespace std;

#include <iostream>

int main()
{
    int t, n, tmp;
    cin >> t;
    for (int v = 0; v < t; v++)
    {
        cin >> n;
        int max = -1;
        for (int i=0; i<n; i++) {
            cin >> tmp;
            if (tmp > max) { max = tmp; }
        }
        cout <<"Case " << v+1 << ": " << max << endl;
    }
}