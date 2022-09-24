#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Kiekiai(double kiek, int kgp, int psp, int &pakkiek, int &stambkiek, double &atskr);
void Kaina(double mkgk, double pk, double spk, int pakkiek, int stambkiek, double atskr, double &stambkain, double &pakkain, double &kgkain);
int main(){
    int n, kgp, psp, pakkiek, stambkiek;
    double mkgk, pk, spk, kg, atskr, stambkain, pakkain, kgkain;

    ifstream df ("miltai.txt");
    ofstream rf ("miltairez.txt");

    df >> n >> kgp >> psp >> mkgk >> pk >> spk;

    for (int i = 0; i < n; i++){
        df >> kg;

        Kiekiai(kg, kgp, psp, pakkiek, stambkiek, atskr);
        Kaina(mkgk, pk, spk, pakkiek, stambkiek, atskr, stambkain, pakkain, kgkain);

        rf << stambkiek << " " << pakkiek << " " << atskr << " " << fixed << setprecision(2) << stambkain << " " << pakkain << " " << kgkain << endl;

    }

    df.close();
    rf.close();

return 0;
}
void Kiekiai(double kiek, int kgp, int psp, int &pakkiek, int &stambkiek, double &atskr)
{
    atskr = int(kiek) % kgp;
    stambkiek = int(kiek - atskr) / kgp / psp;
    pakkiek = int(kiek - atskr) / kgp % psp;
}
void Kaina(double mkgk, double pk, double spk, int pakkiek, int stambkiek, double atskr, double &stambkain, double &pakkain, double &kgkain)
{
    stambkain = spk * stambkiek;
    pakkain = pk * pakkiek;
    kgkain = mkgk * atskr;
}
