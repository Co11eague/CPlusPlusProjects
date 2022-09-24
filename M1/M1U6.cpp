#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
unsigned long long Narys(unsigned long long f1, unsigned long long f2);
int Savybe(unsigned long long narys, int kelintas);
int main(){
    int n, n1, pir = 1, antr = 1, temp, real;
    ifstream df ("fibonati_data.txt");
    ofstream rf ("fibonati_res.txt");

    df >> n;
    n1 = n;
    n = n - 2;

    while (n > 0){

        temp = Narys(pir, antr);
        antr = pir;
        pir = temp;
        n = n - 1;

        real = Savybe(temp, n1 - n);

        while (real > 0){
            if (Savybe(temp, n1 - n))rf << temp << " " << n1 - n << " " << real % 10 << endl;

            real = real / 10;

        }
    }

    rf.close();
    df.close();

return 0;
}
unsigned long long Narys(unsigned long long f1, unsigned long long f2)
{
    return f1 + f2;
}
int Savybe(unsigned long long narys, int kelintas)
{
    int indeks = 0, sk = 0;
    if (kelintas % 3 == 0){
            sk = sk + 1 * pow(10, indeks);
            indeks++;
    }
    if (kelintas % 4 == 0){
            sk = sk + 2 * pow(10, indeks);
            indeks++;
    }
    if (kelintas % 5 == 0){
            sk = sk + 3 * pow(10, indeks);
            indeks++;
    }
    if (kelintas % 15 == 0){
            sk = sk + 4 * pow(10, indeks);
            indeks++;
    }
    if (sk > 0)return sk;
    else return false;

}
