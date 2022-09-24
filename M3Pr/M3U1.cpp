#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Skaito (int A[], int &n);
void Raso(int A[], int n);
void Laikas(int A[], int n, int B[]);
void Klientura(int A[], int n, int val, int minut, int minut1, int &klient);
int main(){
    int A[1000], n, B[1000];

    Skaito(A, n);
    Laikas(A, n, B);
    Raso(B, 120);

return 0;
}
void Skaito (int A[], int &n)
{
    ifstream df ("pirkejai_data.txt");

    df >> n;

    for (int i = 0; i < n * 2; i++)df >> A[i];

    df.close();
}
void Raso(int A[], int n)
{
    ofstream rf ("pirkejai_res.txt");

    for (int i = 0; i < n; i = i + 5)rf << A[i] << " " << A[i + 1] << " " << A[i + 2] << " " << A[i + 3] << " " << A[i + 4] << endl;

    rf.close();
}
void Laikas(int A[], int n, int B[])
{
    int ind = 0, k = 0, i1 = 0;

    for (int i = 8; i < 25; i = i + 1){
        for(int i1 = 0; i1 <= 30; i1 = i1 + 30){
            B[ind] = i;
            ind++;
            B[ind] = i1;
            ind++;
        }

        Klientura(A, n, i, 0, 30, k);

        B[ind] = k;
        ind++;

        for(int i1 = 30; i1 >= 0; i1 = i1 - 30){
            B[ind] = i;
            ind++;
            B[ind] = i1;
            ind++;
        }

        k = 0;
        B[ind - 2] = B[ind - 2] + 1;

        Klientura(A, n, i, 30, 60, k);

        B[ind] = k;
        k = 0;

        ind++;
        }

    }

void Klientura(int A[], int n, int val, int minut, int minut1, int &klient)
{

    for(int i = 0; i < n * 2; i = i + 2){
        if (A[i] == val && minut < A[i + 1] &&  A[i + 1] < minut1)klient++;
        else if (minut1 == 60 && A[i] == val + 1 && minut1 % 60 == A[i + 1])klient++;
        else if (minut1 == 30 && A[i] == val && minut1== A[i + 1])klient++;
    }
}
