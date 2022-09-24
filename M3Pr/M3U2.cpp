#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Skaito (double A[], int &n, double &vis, string B[]);
void Raso(string A[], int n);
void Atrinkimas(double A[], int &n, string B[], double vis);
int main(){
    double A[100], vis;
    string B[100];
    int n;

    Skaito(A, n, vis, B);
    Atrinkimas(A, n, B, vis);
    Raso(B, n);

return 0;
}
void Skaito (double A[], int &n, double &vis, string B[])
{
    ifstream df ("Duomenys.txt");
    double lekt, aps;

    df >> vis >> lekt >> aps >> n;

    vis = vis - lekt * 2 - aps;

    for (int i = 0; i < n; i++)df >> B[i] >> A[i];

    df.close();
}
void Raso(string A[], int n)
{
    ofstream rf ("Rezultatai.txt");

    for (int i = 0; i < n; i++)rf << "Lietuva - " << A[i] << endl;

    rf.close();
}
void Atrinkimas(double A[], int &n, string B[], double vis)
{
    int laik, k = 0;
    string laik1;

    for (int i = 0; i < n; i++){
        for (int i1 = i; i1 < n; i1++){
            if(A[i] > A[i1]){

                laik = A[i];
                A[i] = A[i1];
                A[i1] = laik;

                laik1 = B[i];
                B[i] = B[i1];
                B[i1] = laik1;
            }
        }

    }

    while(vis - A[k] >= 0){
        vis = vis - A[k];
        k++;
    }
    n = k;
}


