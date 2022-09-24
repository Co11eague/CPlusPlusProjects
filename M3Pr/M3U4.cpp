#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Skaito (int &n, int A[], int B[], double C[], int D[]);
void Formuoja(int n, int A[], int B[], int C[], double D[], double E[], double F[]);
void Raso(int n, int A[], int B[], double C[], int D[], int E[], double G[], double F[], int vis, double sum, double nuost);
int Detsum(int n, int A[]);
double Detkain(int n, double A[]);
int main(){
    int A[100], B[100], D[100], E[100], n, N[100];
    double C[100], F[100], G[100];

    Skaito(n, A, B, C, D);
    Formuoja(n, B, D, E, C, F, G);
    Raso(n, A, B, C, D, E, G, F, Detsum(n, D), Detkain(n, F), (Detkain(n, F) - Detkain(n, G)) / Detkain(n, F)  * 100);

return 0;
}
void Skaito (int &n, int A[], int B[], double C[], int D[])
{
    ifstream df ("detales_data.txt");

    df >> n;

    for (int i = 0; i < n; i++)df >> A[i] >> B[i] >> C[i] >> D[i];

    df.close();

}
void Formuoja(int n, int A[], int B[], int C[], double D[], double E[], double F[])
{
    for (int i = 0; i < n; i++){
        C[i] = A[i] - B[i];
        E[i] = D[i] * A[i];
        F[i] = C[i] * D[i];
    }

}
int Detsum(int n, int A[])
{
    int s = 0;

    for (int i = 0; i < n; i++)s = s + A[i];

    return s;
}
void Raso(int n, int A[], int B[], double C[], int D[], int E[], double G[], double F[], int vis, double sum, double nuost)
{
    ofstream rf ("detales_res.txt");

    for (int i = 0; i < n; i++)rf << A[i] << " " << B[i] << " " << fixed << setprecision(2) << C[i] << " " << D[i] << " " << E[i] << " " << fixed << setprecision(2) <<  G[i] << " " << F[i] << endl;

    rf << vis << endl << fixed << setprecision(2) << sum << endl << nuost;

    rf.close();
}
double Detkain(int n, double A[])
{
    double s = 0;

    for (int i = 0; i < n; i++)s = s + A[i];

    return s;
}
