#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Skaito(double A[], double B[], int &n);
void Skirtumas(double A[], double B[], double C[], int n);
double Vidurkis(double A[], int n);
double Santaupos(double vid);
void Raso(double s);
int main(){
    int n;
    double Pr[100], Po[100], Sk[100];

    Skaito(Pr, Po, n);
    Skirtumas(Pr, Po, Sk, n);
    Raso(Santaupos(Vidurkis(Sk, n)));

return 0;
}
void Skaito(double A[], double B[], int &n)
{
    ifstream df ("duomenys.txt");

    df >> n;

    for (int i = 0; i < n; i++)df >> A[i] >> B[i];

    df.close();
}
void Skirtumas(double A[], double B[], double C[], int n)
{
    for (int i = 0; i < n; i++)C[i] = A[i] - B[i];
}
double Vidurkis(double A[], int n){
    double s = 0;

    for (int i = 0; i < n; i++)s = s + A[i];

    return s / n;
}
double Santaupos(double vid)
{
    return (vid * 92 + 500) * 2;
}
void Raso(double s)
{
    ofstream rf ("rezultatai.txt");

    rf << fixed << setprecision(2) << s;

    rf.close();
}
