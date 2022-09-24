#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Skaito (double A[], int &n);
void Raso(double A[], int n);
void Statistika(double A[], int n, double B[]);
int main(){
    double A[100], B[100];
    int n;

    Skaito(A, n);
    Statistika(A, n, B);
    Raso(B, n);

return 0;
}
void Skaito (double A[], int &n)
{
    ifstream df ("sandoriai.txt");

    df >> n;

    for (int i = 0; i < n; i++)df >> A[i];

    df.close();
}
void Raso(double A[], int n)
{
    ofstream rf ("statistika.txt");

    for (int i = 0; i < n; i++){
        if (i == 4 || i == 1 || i == 3)rf << fixed << setprecision(2) << A[i] << endl;
        else rf << fixed << setprecision(0) << A[i] << endl;
    }

    rf.close();
}
void Statistika(double A[], int n, double B[])
{
    int kiein = 0, kisein = 0;
    double ieinvid = 0, iseinvid = 0, peln;

    for (int i = 0; i < n; i++){
            if (A[i] > 0){
                kiein++;
                ieinvid = ieinvid + A[i];
            }
            else if (A[i] < 0){
                kisein++;
                iseinvid = iseinvid + A[i];
            }
    }

    B[0] = kiein;
    B[4] = ieinvid + iseinvid;
    B[2] = kisein;

    if (kiein == 0)B[1] = 0;
    else B[1] = ieinvid / kiein;


    if (kisein == 0)B[3] = 0;
    else B[3] = iseinvid / kisein;

}
