#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Skaito(int &n, string P[], int K[], double KA[]);
void Kainos(int n, string P[], int K[], double KA[], double V[]);
void Raso(double V[]);
int main(){
    int n, K[100];
    double KA[100], V[100];
    string P[100];

    Skaito(n, P, K, KA);
    Kainos(n, P, K, KA, V);
    Raso(V);

return 0;
}
void Skaito(int &n, string P[100], int K[], double KA[])
{
    ifstream df ("produktai_data.txt");

    df >> n;

    for (int i = 0; i < n; i++)df >> P[i] >> K[i] >> KA[i];

    df.close();
}
void Kainos(int n, string P[], int K[], double KA[], double V[])
{
    int ind;

    for(int i = 0; i < 6; i++)V[i] = 0;

    for (int i = 0; i < n; i++){
        if (P[i] == "M")ind = 0;
        else if (P[i] == "D")ind = 1;
        else if (P[i] == "G")ind = 2;
        else if (P[i] == "S")ind = 3;
        else ind = 4;

        V[ind] = V[ind] + K[i] * KA[i];

        V[5] = V[5] +  K[i] * KA[i];

    }
}
void Raso(double V[])
{
    ofstream rf ("produktai_rez.txt");

    rf << fixed << setprecision(1) << "Mesa: " << V[0] << endl << "Darzoves: " << V[1] << endl << "Gerimai: " << V[2] << endl << "Saldumynai: " << V[3] << endl << "Kita: " << V[4] << endl << V[5];

    rf.close();
}
