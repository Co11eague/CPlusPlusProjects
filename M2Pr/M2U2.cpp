#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Info(string &klase, int &moksk, double &dezk);
void Kiekm(int n, int &mok);
void Kaina(int mok, double &dez, double &vis);
int main(){
    string klase;
    int n, mok = 0;
    double dezk, vis = 0;


    ofstream rf ("rezultatai.txt");

    Info(klase, n, dezk);
    Kiekm(n, mok);
    Kaina(mok, dezk, vis);

    rf << klase << endl << mok << endl << fixed << setprecision(1) << dezk << endl << vis << endl;

    rf.close();

return 0;
}
void Info(string &klase, int &moksk, double &dezk)
{
    ifstream df ("klase.txt");

    df >> klase >> moksk >> dezk;

    df.close();
}
void Kiekm(int n, int &mok)
{
    int paz, n1;
    double s = 0;
    string laik;

    ifstream df ("klase.txt");

    df >> laik >> laik >> laik;

    for (int i = 0; i < n; i++){
        df >> n1;

        for(int i1 = 0; i1 < n1; i1++){
            df >> paz;
            s = s + paz;
        }

        if(s / n1 > 8)mok++;
        s = 0;

    }

    df.close();

}
void Kaina(int mok, double &dez, double &vis)
{
    double kof = 1;

    if (mok >= 4 && mok < 7) kof = 0.75;
    else if (mok >= 7 && mok < 10) kof = 0.65;
    else if (mok >= 10)kof = 0.6;

    dez = dez * kof;
    vis = dez * mok;

}
