#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Apsukimas (int &sk, int &sk1);
bool Pirminis (int sk);
int Suma(int sk);
int Kiekis(int sk);
int main(){
    int sk, sk1, s;

    ifstream df ("Skaitmenys.txt");
    ofstream rf ("Rezultatai.txt");

    df >> sk >> sk1;

    Apsukimas(sk, sk1);

    if (Pirminis(sk) && Pirminis(sk1))
    {
        if (sk > sk1)s = Suma(sk);
        else s = Suma(sk1);
    }
    else{
        if (sk < sk1)s = Suma(sk);
        else s = Suma(sk1);
    }

    rf << sk << " " << sk1 << endl << s;

    rf.close();
    df.close();

return 0;
}
void Apsukimas (int &sk, int &sk1)
{
    int k, k1, s = 0;

    k = Kiekis(sk) - 1;
    k1 = Kiekis(sk1) - 1;

    for (k; k >= 0; k--)
    {
        s = s + (sk % 10) * pow(10, k);
        sk = sk / 10;
    }

    sk = s + 1;
    s = 0;

    for (k1; k1 >= 0; k1--)
    {
        s = s + (sk1 % 10) * pow(10, k1);
        sk1 = sk1 / 10;
    }
    sk1 = s + 1;
    //Suluzta ir truksta +1, visur veikia skirtingai.
}
bool Pirminis (int sk)
{
    int k = 2;
    while (sk % k != 0)
    {
        if (k > sk / 2 + 1)return true;
        k++;
    }
    return false;
}
int Suma(int sk)
{
    int s = 0;
    while (sk > 0){
        s = s + sk % 10;
        sk = sk / 10;
    }
    return s;
}
int Kiekis(int sk)
{
    int k = 0;

        while (sk > 0){
        k++;
        sk = sk / 10;
    }
    return k;
}
