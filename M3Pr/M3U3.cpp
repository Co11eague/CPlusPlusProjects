#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Skaito (int A[], int &n, int &a, int &a1);
void Raso(int A[], int n, double vidvis, double vidpard, int k, int B[]);
void Atrinkti(int A[], int n, int a, int a1, int B[], int &k);
double Vidurkis(int A[], int n);
int main(){
    int A[100], n, a, a1, B[100], k = 0;

    Skaito(A, n, a, a1);
    Atrinkti(A, n, a, a1, B, k);
    Raso(A, n, Vidurkis(A, n), Vidurkis(B, k), k, B);

return 0;
}
void Skaito (int A[], int &n, int &a, int &a1)
{
    ifstream df ("sodinukai_data.txt");

    df >> n;

    for (int i = 0; i < n; i++)df >> A[i];

    df >> a >> a1;


    df.close();
}
void Raso(int A[], int n, double vidvis, double vidpard, int k, int B[])
{
    ofstream rf ("sodinukai_res.txt");

    rf << fixed << setprecision(1) << vidvis << endl;
    rf << k << endl;
    rf << fixed << setprecision(1) << vidpard << endl;

    if (B[0] == -1)rf << "NE" << endl;
    else{
        for(int i = 0; i < k; i++){
            rf << B[i] << " ";
        }
    }
    rf << endl;

    rf.close();
}
void Atrinkti(int A[], int n, int a, int a1, int B[], int &k)
{

    for (int i = 0; i < n; i++){
        if(A[i] >= a && A[i] <= a1){
                B[k] = A[i];
                k++;
        }
    }

    if (k == 0)B[0] = -1;
}
double Vidurkis(int A[], int n)
{
    if (n != 0){
        double s = 0;
        for(int i = 0; i < n; i++)s = s + A[i];
        return s / n;
    }
    else return 0;
}
