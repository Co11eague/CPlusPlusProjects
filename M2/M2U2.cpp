#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Krepsinis(int T[], double &indeks, int &met);
int main(){
    string V[100];
    int T[100], met = 0, sk;
    char eil[30];
    double indeks = 0, maxi = -1;


    ifstream df ("Krepsininkai_duom.txt");
    ofstream rf ("Krepsininkai_rez.txt");

    for (int i = 0; i < 2; i++){

            df.ignore();
            df.get(eil, 30);
            V[i] = eil;

            for (int i1 = 0; i1 < 9; i1++){
                df >> T[i1];
            }

            Krepsinis(T, indeks, met);

            rf << V[i] << " " << fixed << setprecision(2) << indeks << " " << met << endl;

            if (maxi < indeks){
                maxi = indeks;
                sk = i;
            }

    }


    rf << "Geresnis yra " << V[sk];

    rf.close();
    df.close();


return 0;
}
void Krepsinis(int T[], double &indeks, int &met)
{
    met = T[0] + T[1] + T[2];
    indeks = double((T[0] * 2 + T[1] * 3 - T[2] + T[3] + T[4] + T[5] + T[6] - T[7])) / T[8];
}
