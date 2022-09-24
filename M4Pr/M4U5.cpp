#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Skaito(int &a, int &b, int &r, int &n, double M[], double U[], int E[]);
void Kmi(int n, double M[], double U[], double K[]);
void Maziausias(double A[], int n, int M[], int &ind);
void Didziausias(double A[], int n, int M[], int &ind);
void Raso(double K[], int &n, double M[], int MM[], int mm, int MD[], int md, int UM[], int um, int UD[], int ud, int E[], double U[]);
int main(){
    int a, b, r, n, MM[100], MD[100], UM[100], UD[100], mm = 0, md = 0, ud = 0, um = 0, E[100];
    double M[100], U[100], K[100];

    Skaito(a, b, r, n, M, U, E);
    Kmi(n, M, U, K);
    Maziausias(M, n, MM, mm);
    Didziausias(M, n, MD, md);
    Maziausias(U, n, UM, um);
    Didziausias(U, n, UD, ud);
    Raso(K, n, M, MM, mm, MD, md, UM, um, UD, ud, E, U);

return 0;
}
void Skaito(int &a, int &b, int &r, int &n, double M[], double U[], int E[])
{
    ifstream df ("sportininkai_data.txt");

    df >> a >> b >> r >> n;

    for (int i = 0; i < n; i++)df >> M[i] >> U[i] >> E[i];

    df.close();
}
void Kmi(int n, double M[], double U[], double K[])
{
    for(int i = 0; i < n; i++)K[i] = M[i] / pow(U[i], 2);
}
void Maziausias(double A[], int n, int M[], int &ind)
{
    int m = 0;

    M[0] = 0;
    ind++;

    for (int i = 1; i < n; i++){
            if (A[m] > A[i]){
                ind = 0;
                m = i;
                M[ind] = i;
                ind++;
            }
            else if(A[m] == A[i]){
                M[ind] = i;
                ind++;
            }

    }
}
void Didziausias(double A[], int n, int M[], int &ind)
{
    int m = 0;

    M[0] = 0;
    ind++;

    for (int i = 1; i < n; i++){
            if (A[m] < A[i]){
                ind = 0;
                m = i;
                M[ind] = i;
                ind++;
            }
            else if(A[m] == A[i]){
                M[ind] = i;
                ind++;
            }

    }
}
void Raso(double K[], int &n, double M[], int MM[], int mm, int MD[], int md, int UM[], int um, int UD[], int ud, int E[], double U[])
{
    ofstream rf ("sportininkai_res.txt");

    for (int i = 0; i < n; i++)rf << i + 1 << " " << fixed << setprecision(0) << K[i] << endl;
    for (int i = 0; i < ud; i++)rf << fixed << setprecision(2) << UD[i] + 1 << " " << M[UD[i]] << " " << U[UD[i]] << " " << E[UD[i]] << " " << fixed << setprecision(0) << K[UD[i]] << endl;
    for (int i = 0; i < um; i++)rf << fixed << setprecision(2) << UM[i] + 1 << " " << M[UM[i]] << " " << U[UM[i]] << " " << E[UM[i]] << " " << fixed << setprecision(0) << K[UM[i]] << endl;
    for (int i = 0; i < mm; i++)rf << fixed << setprecision(2) << MM[i] + 1 << " " << M[MM[i]] << " " << U[MM[i]] << " " << E[MM[i]] << " " << fixed << setprecision(0) << K[MM[i]] << endl;
    for (int i = 0; i < md; i++)rf << fixed << setprecision(2) << MD[i] + 1 << " " << M[MD[i]] << " " << U[MD[i]] << " " << E[MD[i]] << " " << fixed << setprecision(0) << K[MD[i]] << endl;

    rf.close();
}
