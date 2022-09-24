#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

long Naujas (long x);

int main(){
    long n, n1;

    ifstream df ("cikliskas_data.txt");
    ofstream rf ("cikliskas_res.txt");

    df >> n;
    rf << n << endl;

    n1 = n;
    n1 = n1 / 10;

    while (n1 > 0){
        n = Naujas(n);
        rf << n << endl;

        n1 = n1 / 10;
    }

    rf.close();
    df.close();

return 0;
}
long Naujas (long x)
{
    long x2;
    int k = -1;

    x2 = x;

    while  (x2 > 0){
        x2 = x2 / 10;
        k++;
    }

    return x % 10 * pow(10, k) + x / 10;

}
