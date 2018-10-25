//problem: 6929
//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4941

#include <iostream>
#include <cmath>
using namespace std;

const double eps = 0.0000000001;

int main() {
    // load input
    int t;
    cin >> t;
    int n, base;
    for (int p=0; p<t; p++) {
        cin >> n;
        //delete impossible case (the power of 2)
        if((n & (n - 1)) == 0){// power of 2
            cout << "IMPOSSIBLE\n";
        } else{
            double x, quotient, tmp;
            int i=0;
            // for possible solution cardinality
            for(i=2; ;i++){
                quotient = ((double)n)/i;

                // check if the cardinality is correct
                tmp = quotient;
                if(0==i%2){ //pari: check 2.5
                    tmp -= 0.5;
                }//else{}//dispari: check 2.0

                if(abs(tmp-floor(tmp))<eps){
                    // compute the first number
                    base = int(floor(quotient)) - ((i-1)/2);
                    break;
                }
            }
            //generate output
            cout << n << " = " << base;
            for(int j=base+1; j<base+i; j++){
                cout << " + " << j;
            }
            cout << "\n";
        }
    }
}