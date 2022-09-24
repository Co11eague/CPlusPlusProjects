#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
void Skaito(int P[], int A[], int T[], int &n);
int Maziausias(int A[], int n);
int Didziausias(int A[], int n);
void Paprasti(int P[], int A[], int T[], int n, int U[], int &ind);
void Raso(int A[], int n);
using namespace std;
int main(){
    int P[100], A[100], T[100], n, U[100], ind = 0;

    Skaito(P, A, T, n);
    Paprasti(P, A, T, n, U, ind);
    Raso(U, ind);

return 0;
}
void Skaito(int P[], int A[], int T[], int &n)
{
    ifstream df ("paprasti_uzdaviniai_data.txt");

    df >> n;

    for (int i = 0; i < n; i++)df >> P[i];
    for (int i = 0; i < n; i++)df >> A[i];
    for (int i = 0; i < n; i++)df >> T[i];

    df.close();
}
int Maziausias(int A[], int n)
{
    int ind = 0;

    for (int i = 0; i < n; i++)if(A[i] < A[ind])ind = i;

    return A[ind];

}
int Didziausias(int A[], int n)
{
    int ind = 0;

    for (int i = 0; i < n; i++)if(A[i] > A[ind])ind = i;

    return A[ind];

}
void Paprasti(int P[], int A[], int T[], int n, int U[], int &ind)
{
    int pm = Maziausias(P, n), am = Maziausias(A, n), tm = Maziausias(T, n), pd = Didziausias(P, n), ad = Didziausias(A, n), td = Didziausias(T, n);

    for(int i = 0; i < n; i++){
        if(P[i] == pm && A[i] == am && T[i] != td || P[i] == pm && T[i] == tm && A[i] != ad || T[i] == tm && A[i] == am && P[i] != pd){
            U[ind] = i + 1;
            ind++;
        }
    }
}
void Raso(int A[], int n){

    ofstream rf ("paprasti_uzdaviniai_res.txt");

    for (int i = 0; i < n; i++){
        rf << A[i] << " ";
    }

    rf.close();
}
