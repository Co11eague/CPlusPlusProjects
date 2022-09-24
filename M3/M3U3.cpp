#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Skaito (int A[], int &n, int &m);
void Raso(int A[], int m, double vid);
void Laikaidid(int n, int m, int A[], int B[]);
double Vidurkis(int A[], int n);
int main(){
    int A[100], n, m, B[100];

    Skaito(A, n, m);
    Laikaidid(n, m, A, B);
    Raso(B, m, Vidurkis(B, m));

return 0;
}
void Skaito (int A[], int &n, int &m)
{
    ifstream df ("nuotraukos_data.txt");

    df >> n >> m;

    for (int i = 0; i < n * m; i++)df >> A[i];

    df.close();
}
void Raso(int A[], int m, double vid)
{
    ofstream rf ("nuotraukos_res.txt");

    for (int i = 0; i < m; i++){
        rf << A[i];
        if(i != m - 1)rf << ", ";
    }

    rf << endl << fixed << setprecision(1) << vid;

    rf.close();
}
void Laikaidid(int n, int m, int A[], int B[])
{
    int ind = 0, s = 0, s1 = 0;

    for (int i = 0; i < n; i++){
        for(int i1 = 0; i1 < m; i1++)s1 = s1 + A[i * m + i1];
        if (s1 > s){
            s = s1;
            ind = i;
        }
    }

    for (int i = 0; i < m; i++)B[i] = A[ind * m + i];
}
double Vidurkis(int A[], int n)
{
    double s = 0;

    for (int i = 0; i < n; i++)s = s + A[i];

    return s / n;
}
