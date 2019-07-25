#include <bits/stdc++.h>

using namespace std;

int digits(int x)  
{  
    x = abs(x);  
    return (x < 10 ? 1 :   
        (x < 100 ? 2 :   
        (x < 1000 ? 3 :   
        (x < 10000 ? 4 :   
        (x < 100000 ? 5 :   
        (x < 1000000 ? 6 :
        7))))));  
}  

int main() {
    int n;
    int c=0;
    while (cin >> n) {
        if (n==0) break;

        int sum = 0,num;

        for (int i=0; i<n; i++) {
            cin >> num;
            sum += num;
        }

        int div = __gcd(sum,n);

        num = sum/div; // Numerator of the resulting frac
        div = n/div;    // Divisor of resulting frac
        
        cout << "Case " << ++c << ":\n";
        if (div < 0) { div *= (-1); num *= (-1); }
        if (div == 1) {
            if (num < 0) cout << "- " << abs(num) << endl;
            else cout << num << endl;
        } else if (abs(num) > div) {
            int a = num/div;
            num -= a*div;
            int dashes = max(digits(num),digits(div));
            for (int i=0; i<digits(a)+(a<0?2:0)+dashes-digits(num); i++) cout <<' ';
            cout << abs(num) << endl;
            if (a < 0) cout << "- " << abs(a); else cout << a;
            for (int i=0; i<dashes; i++) cout << "-";
            cout << endl;
            for (int i=0; i<digits(a)+(a<0?2:0)+dashes-digits(div); i++) cout <<' ';
            cout << abs(div) << endl;
        } else if (abs(num) < div) {
            int dashes = max(digits(num),digits(div));
            for (int i=0; i<(num<0?2:0)+dashes-digits(num); i++) cout <<' ';
            cout << abs(num) << endl;
            if (num < 0) cout << "- ";
            for (int i=0; i<dashes; i++) cout << "-";
            cout << endl;
            for (int i=0; i<(num<0?2:0)+dashes-digits(div); i++) cout <<' ';
            cout << abs(div) << endl;
        }
    }

    return 0;
}