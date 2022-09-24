#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Skaito(int A[], int &n);
void Kiekis(int A[], int n, double B[]);
void Raso(double A[], int n);
int main(){
    int A[100], n;
    double B[100];

    Skaito(A, n);
    Kiekis(A, n, B);
    Raso(B, 3);

return 0;
}
void Skaito (int A[], int &n)
{
    ifstream df ("data.txt");

    df >> n;

    for (int i = 0; i < n; i++)df >> A[i];

    df.close();
}
void Kiekis(int A[], int n, double B[])
{
    for(int i = 0; i < 3; i++)B[i] = 0;

    for (int i = 0; i < n; i++){
        B[0] = B[0] + A[i] * 10.3;
        B[1] = B[1] + A[i] * 15.2;
        B[2] = B[2] + A[i] * 100;
    }
}
void Raso(double A[], int n)
{
    ofstream rf ("results.txt");

    for (int i = 0; i < n; i++)rf << fixed << setprecision(0) << A[i] << " ";

    rf.close();
}
