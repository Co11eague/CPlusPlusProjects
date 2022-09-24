#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Skaito(int &n, string D[], int K[], int P[], int &vis);
void Kiekis(int n, int K[], int P[], int G[]);
int Kelios(int kiek, int did);
void Atrinkti(int P[], int n, int I[], int &ind, int vis);
void Raso(string D[], int G[], int n, int ind, int I[]);
int main(){
    int n, vis, K[100], P[100], ind = 0, I[100], G[100];
    string D[100];

    Skaito(n, D, K, P, vis);
    for (int i = 0; i < n; i++)G[i] = Kelios(P[i], K[i]);
    Atrinkti(P, n, I, ind, vis);
    Raso(D, G, n, ind, I);

return 0;
}
void Skaito(int &n, string D[], int K[], int P[], int &vis)
{
    ifstream df ("pasirinkimas_data.txt");

    df >> n >> vis;

    for(int i = 0; i < n; i++)df >> D[i] >> P[i] >> K[i];

    df.close();
}
int Kelios(int kiek, int did)
{
    if (kiek % did > 0)return kiek / did + 1;
    else return kiek / did;
}
void Atrinkti(int P[], int n, int I[], int &ind, int vis)
{
    for (int i = 0; i < n; i++){
        if(P[i] < vis / 2){
            I[ind] = i;
            ind++;
        }
    }
}
void Raso(string D[], int G[], int n, int ind, int I[])
{
    ofstream rf ("pasirinkimas_res.txt");

    rf << "VISI DALYKAI:" << endl;
    for(int i = 0; i < n; i++)rf << D[i] << " " << G[i] << endl;

    rf << "ATRINKTI DALYKAI:" << endl;
    for(int i = 0; i < ind; i++)rf << D[I[i]] << " " << G[I[i]] << endl;

    if(ind == 0)rf << "nera";

    rf.close();
}
