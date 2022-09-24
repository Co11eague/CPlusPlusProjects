#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Skaito(int &n, int A[], int B[]);
int Suma(int n, int A[]);
double Vidurkis(int n, int A[], int B[]);
void Raso(double vidm, double vidkm);
int main(){
    int n, K[100], L[100];

    Skaito(n, K, L);
    Raso(Vidurkis(n, K, L), Vidurkis(n, K, L) * 3600 / 1000);

return 0;
}
void Skaito(int &n, int A[], int B[])
{
    ifstream df ("kelione.txt");

    df >> n;

    for (int i = 0; i < n; i++)df >> A[i] >> B[i];

    df.close();
}
int Suma(int n, int A[])
{
    int s = 0;

    for (int i = 0; i < n; i++)s = s + A[i];

    return s;
}
double Vidurkis(int n, int A[], int B[])
{
    double vid;

    vid = Suma(n, A);

    return vid / Suma(n, B);
}
void Raso(double vidm, double vidkm)
{
    ofstream rf ("rezultatai.txt");

    rf << fixed << setprecision(2) << vidm << " " << vidkm;

    rf.close();
}
