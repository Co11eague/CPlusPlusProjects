#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Skaito (int A[], int &n);
void Raso(int tri, double vid);
int Suma (int A[], int n);
double Vidurkis(int A[], int n);
int main(){
    int A[100], n;

    Skaito(A, n);
    Raso(Suma(A, n), Vidurkis(A, n));

return 0;
}
void Skaito (int A[], int &n)
{
    ifstream df ("duom.txt");

    df >> n;

    for (int i = 0; i < n; i++)df >> A[i];

    df.close();
}
void Raso(int tri, double vid)
{
    ofstream rf ("rez.txt");

    rf << tri << " " << fixed << setprecision(1) << vid << endl;

    rf.close();
}
int Suma(int A[], int n)
{
    int s = 0;

    for(int i = 0; i < n; i++)s = s + A[i];

    return s;
}
double Vidurkis(int A[], int n)
{
    double s = 0;

    for (int i = 0; i < n; i++)s = s + A[i];

    return s / n;
}
