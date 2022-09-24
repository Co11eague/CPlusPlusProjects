#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Skaito(int &n, int &m, double A[]);
double Suma(int n, int m, double A[]);
double Vidurkis(double s, int n);
double Vaikinas(int n, int m, double A[]);
double Mergina(int n, int m, double A[]);
void Raso(double vis, double vid, double vaik, double merg);
int main(){
    int n, m;
    double A[100];

    Skaito(n, m, A);
    Raso(Suma(n, m, A), Vidurkis(Suma(n, m, A), n), Vaikinas(n, m, A), Mergina(n, m, A));

return 0;
}
void Skaito(int &n, int &m, double A[])
{
    ifstream df ("duom.txt");

    df >> n >> m;

    for(int i = 0; i < n * m; i++)df >> A[i];

    df.close();
}
double Suma(int n, int m, double A[])
{
    double s = 0;

    for (int i = 0; i < n * m; i++)s = s + A[i];

    return s;
}
double Vidurkis(double s, int n)
{
    return s / n;
}
double Vaikinas(int n, int m, double A[])
{
    double s = 0, s1 = 0;

    for (int i = 0; i < n; i++){
            for(int i1 = 0; i1 < m; i1++)s1 = s1 + A[i * m + i1];
        if(s1 <= 20)s = s + s1;
        s1 = 0;
    }

    return s;
}
double Mergina(int n, int m, double A[])
{
    double s = 0, s1 = 0;

    for (int i = 0; i < n; i++){
            for(int i1 = 0; i1 < m; i1++)s1 = s1 + A[i * m + i1];
        if(s1 > 20)s = s + s1;
        s1 = 0;
    }

    return s;
}
void Raso(double vis, double vid, double vaik, double merg)
{
    ofstream rf ("rez.txt");

    rf << fixed << setprecision(2) << vis << endl << fixed << setprecision(3) << vid << endl << "Vaikinas isleido - " << fixed << setprecision(2) << vaik << endl << "Mergina isleido - " << merg;

    rf.close();
}
