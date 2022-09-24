#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Skaito (int A[], int B[]);
void Raso(int l, int t);
int Laimejo(int A[], int B[]);
int Traukimas(int A[]);
int main(){
    int A[100], B[100], l, t;

    Skaito(A, B);
    l = Laimejo(A, B);
    t = Traukimas(A);
    Raso(l, t);

    return 0;
}
void Skaito (int A[], int B[])
{
    ifstream df ("data.txt");

    for (int i = 0; i < 6; i++)df >> A[i];
    for (int i = 0; i < 6; i++)df >> B[i];

    df.close();
}
void Raso(int l, int t)
{
    ofstream rf ("results.txt");

    rf << l << " ";

    if (t != 2)rf << t;

    rf.close();
}
int Laimejo(int A[], int B[])
{
    int s = 0, s1 = 0, i = 0;
    while (A[i]!=0 && i < 5){
        s = s + A[i];
        i++;
    }

    i = 0;

    while (B[i]!= 0 && i < 6){
        s1 = s1 + B[i];
        i++;
    }


    if (s > s1 && s <= 7 || s1 > 7 && s <= 7)return 0;
    else if (s1 > s && s1 <= 7 || s > 7 && s1 <= 7)return 1;
    else if (s1 == s && s <= 7)return 2;
    else return 3;
}
int Traukimas(int A[])
{
    int s = 0, i = 0;

    while (A[i]!=0 && i < 5){
        s = s + A[i];
        i++;
    }

    if(i != 5 && s < 7 && s + A[i + 1] <= 7)return 0;
    else if(i != 5 && s < 7 && s + A[i + 1] > 7)return 1;
    else return 2;
}
