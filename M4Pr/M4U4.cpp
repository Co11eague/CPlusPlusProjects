#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Skaito(string A[], int B[], int &n, int &m);
void Atsakymai(int B[], int &m, int k, int &t, int &n);
void Geriausios(int T[], int NT[], int &n, int G[], int &ind);
void Raso(string A[], int T[], int NT[], int &n, int G[], int &ind);
int main(){
    string A[100];
    int B[100], n, m, t = 0, nt = 0, T[100], N[100], G[100], ind = 0;

    Skaito(A, B, n, m);

    for (int i = 0; i < n; i++){
        Atsakymai(B, m, i, t, nt);
        T[i] = t;
        N[i] = nt;
        t = 0;
        nt = 0;
    }

    Geriausios(T, N, n, G, ind);
    Raso(A, T, N, n, G, ind);




return 0;
}
void Skaito(string A[], int B[], int &n, int &m)
{
    ifstream df ("protmusis_data.txt");

    df >> n >> m;

    for(int i = 0; i < n; i++){
            df >> A[i];
        for(int i1 = 0; i1 < m; i1++)df >> B[i1 + i * m];
    }

    df.close();
}
void Atsakymai(int B[], int &m, int k, int &t, int &n)
{
    for(int i = 0; i < m; i++){
        if(B[i + k * m])t++;
        else n++;
    }
}
void Geriausios(int T[], int NT[], int &n, int G[], int &ind){
    for (int i = 0; i < n; i++){
            if(T[i] > NT[i]){
                G[ind] = i;
                ind++;
            }
    }
}
void Raso(string A[], int T[], int NT[], int &n, int G[], int &ind)
{
    ofstream rf ("protmusis_res.txt");

    rf << "VISOS KOMANDOS:" << endl;

    for (int i = 0; i < n; i++){
        rf << A[i] << " " << T[i] << " " << NT[i] << endl;
    }

    rf << "GERIAUSIOS KOMANDOS:" << endl;

    if (ind > 0){
        for (int i = 0; i < ind; i++)rf << A[G[i]] << " " << T[G[i]] << " " << NT[G[i]] << endl;
    }
    else rf << "nera";

    rf.close();
}
