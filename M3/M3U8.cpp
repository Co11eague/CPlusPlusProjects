#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Skaito(int A[], int &n, int &m);
double Suma(int A[], int n);
double Vidurkis(double s, int n);
void Vidurkiai(int A[], int n, int m, double B[]);
void Dudid(double A[], int n, double &pirm, double &antr);
void Raso(double vid, double vid1);
int main(){
    int A[1000], n, m;
    double B[100], pirm = 0, antr = 0;

    Skaito(A, n, m);
    Vidurkiai(A, n, m, B);
    Dudid(B, n, pirm, antr);
    Raso(pirm, antr);

return 0;
}
void Skaito(int A[], int &n, int &m)
{
    ifstream df ("pazymiai.txt");

    df >> n >> m;

    for(int i = 0; i < n * m; i++)df >> A[i];

    df.close();
}
void Vidurkiai(int A[], int n, int m, double B[])
{
    int C[100];
    for(int i = 0; i < n; i++){
        for (int i1 = 0; i1 < m; i1++)C[i1] = A[i * m + i1];
        B[i] = Vidurkis(Suma(C, m), m);
    }
}
double Vidurkis(double s, int n)
{
    return s / n;
}
void Dudid(double A[], int n, double &pirm, double &antr)
{
    for(int i = 0; i < n; i++){
        if (A[i] > pirm){
                antr = pirm;
                pirm = A[i];
        }
        else if (A[i] > antr)antr = A[i];
}
}
void Raso(double vid, double vid1)
{
    ofstream rf ("rezultatai.txt");

    rf << fixed << setprecision(2) << vid << " " << vid1;

    rf.close();
}
double Suma(int A[], int n)
{
    int s = 0;

    for(int i = 0; i < n; i++)s = s + A[i];

    return s;
}
