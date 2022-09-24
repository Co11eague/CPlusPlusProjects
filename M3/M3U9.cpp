#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Skaito(int &n, int A[], int B[]);
void Duom(int n, int A[], int B[], double &ak, double &aka, double &akav);
void Raso(double ak, double aka, double akav);
int main(){
    int n, K[100], Ka[100];
    double ak, aka, akav;

    Skaito(n, K, Ka);
    Duom(n, K, Ka, ak, aka, akav);
    Raso(ak, aka, akav);

return 0;
}
void Skaito(int &n, int A[], int B[])
{
    ifstream df ("duomenys.txt");

    df >> n;

    for (int i = 0; i < n; i++)df >> A[i] >> B[i];

    df.close();
}
void Duom(int n, int A[], int B[], double &ak, double &aka, double &akav)
{
    double skiek = 0, skain = 0;

    for(int i = 0; i < n; i++){
            skiek = skiek + A[i];
            skain = skain + A[i] * B[i];
    }

    ak = skiek / n;
    aka = skain / skiek;
    akav = skain / n;
}
void Raso(double ak, double aka, double akav)
{
    ofstream rf ("rezultatai.txt");

    rf << fixed << setprecision(0) << ak << endl << aka << endl << akav;

    rf.close();
}
